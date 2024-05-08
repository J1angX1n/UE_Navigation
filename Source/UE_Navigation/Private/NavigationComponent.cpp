// Fill out your copyright notice in the Description page of Project Settings.


#include "NavigationComponent.h"
#include "NavGameInstanceSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "NavigationTargetComponent.h"



// Sets default values for this component's properties
UNavigationComponent::UNavigationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	show = false;
	widgetWithin = NULL;
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
	
	// ...
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

		if (widgetWithin)
		{
			UIHalfWidth = widgetWithin->GetDesiredSize().X;
			UIHalfHeight = widgetWithin->GetDesiredSize().Y;
		}

		for (size_t i = 0; i < len; i++)
		{
			worldPos = targets[i]->GetActorLocation();

			//TODO ���Ƕ�̬�Ƴ������
			UNavigationTargetComponent* targetCom = targets[i]->GetComponentByClass<UNavigationTargetComponent>();

			//������ά����ӳ�䵽��ά�������
			targetCom->UpdateScreenPosition();
			//�����ά����ʵ������Ļ����ʾ��λ��
			targetCom->GetPosOnScreen(UIHalfWidth, UIHalfHeight);

			UNavData* data = targetCom->GetNavData();

			//if (data->behind)
			//{
			//	if (abs(data->realPos.X - 0) <= 1e-6)
			//	{
			//		data->realPos.Y = fmax(data->realPos.Y, screenHeight - abs(data->pos_x));
			//	}
			//	else if (abs(data->realPos.X - screenWidth) <= 1e-6)
			//	{
			//		data->realPos.Y = fmax(data->realPos.Y, screenHeight - abs(screenWidth - data->pos_x));
			//	}
			//	else
			//	{
			//		data->realPos.Y = screenHeight;
			//	}

			//}

			//�������
			FVector dir = worldPos - selfPos;
			data->distance = dir.Length() - targetCom->GetDiff();

			datas.Add(data);
		}
	}

	return datas;
}
