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
	FVector2D screenPos;

	if (world)
	{
		APlayerController* pc = UGameplayStatics::GetPlayerController(world, 0);
		UGameInstance* ins = UGameplayStatics::GetGameInstance(world);
		UNavGameInstanceSubsystem* sys = ins->GetSubsystem<UNavGameInstanceSubsystem>();

		TArray<AActor*> targets = sys->GetTargets();
		size_t len = targets.Num();

		AActor* owner = GetOwner();
		selfPos = owner->GetActorLocation();

		for (size_t i = 0; i < len; i++)
		{
			UNavData* data = NewObject<UNavData>();

			worldPos = targets[i]->GetActorLocation();
			bool behind = DeprojectWorldToScreen(pc, worldPos, screenPos, false);

			//¼ÆËã¾àÀë
			FVector dir = worldPos - selfPos;

			data->pos_x = screenPos.X;
			data->pos_y = screenPos.Y;
			data->behind = behind;
			data->distance = dir.Length();
			data->angle = 0;

			datas.Add(data);
		}
	}

	return datas;
}

bool UNavigationComponent::DeprojectWorldToScreen(APlayerController const* Player, const FVector& WorldPosition, FVector2D& ScreenPosition, bool bPlayerViewportRelative)
{
	ULocalPlayer* const LP = Player ? Player->GetLocalPlayer() : nullptr;
	if (LP && LP->ViewportClient)
	{
		// get the projection data
		FSceneViewProjectionData ProjectionData;
		if (LP->GetProjectionData(LP->ViewportClient->Viewport, /*out*/ ProjectionData))
		{
			FMatrix const ViewProjectionMatrix = ProjectionData.ComputeViewProjectionMatrix();
			bool bResult = FSceneView::ProjectWorldToScreen(WorldPosition, ProjectionData.GetConstrainedViewRect(), ViewProjectionMatrix, ScreenPosition);

			if (bPlayerViewportRelative)
			{
				ScreenPosition -= FVector2D(ProjectionData.GetConstrainedViewRect().Min);
			}

			bResult = bResult && Player->PostProcessWorldToScreen(WorldPosition, ScreenPosition, bPlayerViewportRelative);
			return bResult;
		}
	}

	ScreenPosition = FVector2D::ZeroVector;
	return false;
}