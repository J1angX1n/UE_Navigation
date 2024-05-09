// Fill out your copyright notice in the Description page of Project Settings.


#include "NavigationComponent.h"
#include "NavGameInstanceSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "NavigationTargetComponent.h"
#include "Components/TextBlock.h"


// Sets default values for this component's properties
UNavigationComponent::UNavigationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	show = false;
	widgetWithin = NULL;
	widgetOutside = NULL;
}


// Called when the game starts
void UNavigationComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UNavigationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	UpdateNavigation();
}

bool UNavigationComponent::UpdateNavigation()
{
	if (!widgetWithin)
	{
		return false;
	}

	//没有设置屏幕外指示图标的话就用屏幕内的代替之
	if (!widgetOutside)
	{
		widgetOutside = widgetWithin;
	}

	UWorld* world = GetWorld();

	if (world)
	{
		UGameInstance* ins = UGameplayStatics::GetGameInstance(world);
		UNavGameInstanceSubsystem* sys = ins->GetSubsystem<UNavGameInstanceSubsystem>();

		FVector2D screenSize;
		world->GetGameViewport()->GetViewportSize(screenSize);
		double screenWidth = screenSize.X, screenHeight = screenSize.Y;

		int16 num = sys->GetTargetNum();

		//保持屏幕上的指示图标数量与NavigationTargetComponent实例数量一致
		while (m_NavWidgets.Num() > num)
		{
			m_NavWidgets[0]->RemoveFromParent();
			m_NavWidgets.Pop();
		}

		while (m_NavWidgets.Num() < num)
		{
			UUserWidget* instance = CreateWidget<UUserWidget>(world, widgetWithin);
			instance->AddToViewport();
			m_NavWidgets.Add(instance);
		}

		TArray<UNavData*> NavDatas = GetAllNavDatas();

		for (uint16 i = 0; i < num; i++)
		{
			UUserWidget* instance = m_NavWidgets[i];
			UNavData* data = NavDatas[i];
			FVector2D UISize = instance->GetDesiredSize();

			//计算得到的真实位置是图片渲染的左上角，需要减去UI大小的一半将其居中
			FVector2D diff = UISize / 2;

			//真实位置处于屏幕边界时要稍微调整图片位置使其能完整显示，不能直接修改realPos的值，那样位置会发生变化
			bool outside = false;
			if (data->realPos.X < UISize.X / 2)
			{
				diff.X -= UISize.X / 2 - data->realPos.X;
				outside = true;
			}
			if (data->realPos.Y < UISize.Y / 2)
			{
				diff.Y -= UISize.Y / 2 - data->realPos.Y;
				outside = true;
			}

			if (data->realPos.X > screenWidth - UISize.X / 2)
			{
				diff.X += UISize.X / 2 - (screenWidth - data->realPos.X);
				outside = true;
			}
			if (data->realPos.Y > screenHeight - UISize.Y / 2)
			{
				diff.Y += UISize.Y / 2 - (screenHeight - data->realPos.Y);
				outside = true;
			}
			
			UTextBlock* textDistance = Cast<UTextBlock>(instance->GetWidgetFromName(TEXT("TextDistance")));
			if (textDistance)
			{
				textDistance->SetText(FText::AsNumber(data->distance));
			}
			
			instance->SetPositionInViewport(data->realPos - diff);
		}
		
		return true;
	}
	
	return false;
}

bool UNavigationComponent::GetShow()
{
	return show;
}

void UNavigationComponent::SetShow(bool value)
{
	show = value;
}

TArray<UNavData*> UNavigationComponent::GetAllNavDatas()
{
	TArray<UNavData*> datas;

	UWorld* world = GetWorld();
	FVector worldPos, selfPos;
	FVector2D screenPos, screenSize;

	double UIHalfWidth = 0, UIHalfHeight = 0;

	if (world)
	{
		UGameInstance* ins = UGameplayStatics::GetGameInstance(world);
		UNavGameInstanceSubsystem* sys = ins->GetSubsystem<UNavGameInstanceSubsystem>();

		TArray<AActor*> targets = sys->GetTargets();
		size_t len = targets.Num();

		AActor* owner = GetOwner();
		selfPos = owner->GetActorLocation();

		world->GetGameViewport()->GetViewportSize(screenSize);
		double screenWidth = screenSize.X, screenHeight = screenSize.Y;

		//if (widgetWithin)
		//{
		//	UIHalfWidth = widgetWithin->GetDesiredSize().X;
		//	UIHalfHeight = widgetWithin->GetDesiredSize().Y;
		//}

		for (size_t i = 0; i < len; i++)
		{
			worldPos = targets[i]->GetActorLocation();

			//TODO 考虑动态移除的情况
			UNavigationTargetComponent* targetCom = targets[i]->GetComponentByClass<UNavigationTargetComponent>();

			//计算三维坐标映射到二维后的坐标
			targetCom->UpdateScreenPosition();
			//计算二维坐标实际在屏幕上显示的位置
			targetCom->GetPosOnScreen(0, 0);

			UNavData* data = targetCom->GetNavData();

			//计算距离
			FVector dir = worldPos - selfPos;
			data->distance = dir.Length() - targetCom->GetDiff();

			datas.Add(data);
		}
	}

	return datas;
}
