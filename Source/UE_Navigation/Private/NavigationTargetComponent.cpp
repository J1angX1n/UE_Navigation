// Fill out your copyright notice in the Description page of Project Settings.


#include "NavigationTargetComponent.h"
#include "NavGameInstanceSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Containers/Array.h"
#include "GameFramework/Actor.h"
#include "NavData.h"
#include "GameFramework/PlayerController.h"

// Sets default values for this component's properties
UNavigationTargetComponent::UNavigationTargetComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	m_NavData = NULL;

	// ...
}


// Called when the game starts
void UNavigationTargetComponent::BeginPlay()
{
	Super::BeginPlay();

	UWorld* world = GetWorld();

	if (world)
	{
		UGameInstance* gameIns = UGameplayStatics::GetGameInstance(world);
		UNavGameInstanceSubsystem* subsystem = gameIns->GetSubsystem<UNavGameInstanceSubsystem>();
		
		AActor* target = GetOwner();
		subsystem->AddTarget(target);
	}
}

bool UNavigationTargetComponent::GetIntersectedPoint(FVector2D p1, FVector2D p2, FVector2D p3, FVector2D p4, FVector2D& res)
{
	FVector2D vec1 = p2 - p1, vec2 = p4 - p3;
	
	double cross = UKismetMathLibrary::CrossProduct2D(vec1, vec2);

	//平行
	if (cross == 0)
	{
		return false;
	}

	double t = UKismetMathLibrary::CrossProduct2D(p3 - p1, vec2) / cross;
	double u = UKismetMathLibrary::CrossProduct2D(vec1, p1 - p3) / cross;

	//线段不共线但不相交
	if (t < 0 || t>1 || u < 0 || u>1)
	{
		return false;
	}

	res = p1 + t * vec1;
	return true;
}



// Called every frame
void UNavigationTargetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UNavigationTargetComponent::UpdateScreenPosition()
{
	UWorld* world = GetWorld();
	FVector worldPos;
	FVector2D screenPos;

	APlayerController* pc = UGameplayStatics::GetPlayerController(world, 0);

	if (world)
	{
		worldPos = GetOwner()->GetActorLocation();
		bool behind = !DeprojectWorldToScreen(pc, worldPos, screenPos, false);

		if (!m_NavData)
		{
			m_NavData = NewObject<UNavData>(/*this*/);
		}
		
		m_NavData->pos_x = screenPos.X;
		m_NavData->pos_y = screenPos.Y;
		m_NavData->behind = behind;
		m_NavData->angle = 0;
	}
}

bool UNavigationTargetComponent::ProjectWorldToScreen(const FVector& WorldPosition, const FIntRect& ViewRect, const FMatrix& ViewProjectionMatrix, FVector2D& out_ScreenPos, bool bShouldCalcOutsideViewPosition /*= false*/)
{
	FPlane Result = ViewProjectionMatrix.TransformFVector4(FVector4(WorldPosition, 1.f));
	bool bIsInsideView = Result.W > 0.0f;
	double W = Result.W;

	if (Result.W < 0)
	{
		Result.W = -Result.W;
	}
	else if (Result.W == 0)
	{
		Result.W = 1e-6;
	}

	// Tweak our W value to allow the outside view position calcs if the variable is enabled.
	if (bShouldCalcOutsideViewPosition)
	{
		W = FMath::Abs(Result.W);
	}

	// the result of this will be x and y coords in -1..1 projection space
	const float RHW = 1.0f / W;
	FPlane PosInScreenSpace = FPlane(Result.X * RHW, Result.Y * RHW, Result.Z * RHW, W);

	// Move from projection space to normalized 0..1 UI space
	const float NormalizedX = (PosInScreenSpace.X / 2.f) + 0.5f;
	const float NormalizedY = 1.f - (PosInScreenSpace.Y / 2.f) - 0.5f;

	FVector2D RayStartViewRectSpace(
		(NormalizedX * (float)ViewRect.Width()),
		(NormalizedY * (float)ViewRect.Height())
	);

	out_ScreenPos = RayStartViewRectSpace + FVector2D(static_cast<float>(ViewRect.Min.X), static_cast<float>(ViewRect.Min.Y));

	return bIsInsideView;
}

bool UNavigationTargetComponent::DeprojectWorldToScreen(APlayerController const* Player, const FVector& WorldPosition, FVector2D& ScreenPosition, bool bPlayerViewportRelative)
{
	ULocalPlayer* const LP = Player ? Player->GetLocalPlayer() : nullptr;
	if (LP && LP->ViewportClient)
	{
		// get the projection data
		FSceneViewProjectionData ProjectionData;
		if (LP->GetProjectionData(LP->ViewportClient->Viewport, /*out*/ ProjectionData))
		{
			FMatrix const ViewProjectionMatrix = ProjectionData.ComputeViewProjectionMatrix();
			bool bResult = ProjectWorldToScreen(WorldPosition, ProjectionData.GetConstrainedViewRect(), ViewProjectionMatrix, ScreenPosition);

			if (bPlayerViewportRelative)
			{
				ScreenPosition -= FVector2D(ProjectionData.GetConstrainedViewRect().Min);
			}

			Player->PostProcessWorldToScreen(WorldPosition, ScreenPosition, bPlayerViewportRelative);
			
			return bResult;
		}
	}

	ScreenPosition = FVector2D::ZeroVector;
	return false;
}

void UNavigationTargetComponent::GetPosOnScreen(double UIHalfWidth, double UIHalfHeight)
{
	FVector2D originPos = FVector2D(m_NavData->pos_x, m_NavData->pos_y);
	FVector2D screenSize;

	UWorld* world = GetWorld();

	if (!world)
	{
		return;
	}

	world->GetGameViewport()->GetViewportSize(screenSize);

	double screenWidth = screenSize.X, screenHeight = screenSize.Y;
	double screenHalfWidth = screenSize.X / 2;
	double screenHalfHeight = screenSize.Y / 2;

	FVector2D center(screenHalfWidth, screenHalfHeight);
	m_NavData->realPos = FVector2D(m_NavData->pos_x, m_NavData->pos_y);
	if (m_NavData->pos_x >= 0 && m_NavData->pos_x <= screenHalfWidth * 2 && m_NavData->pos_y >= 0 && m_NavData->pos_y <= screenHalfHeight * 2)
	{
		return;
	}

	// TODO 即使是上方与左侧位置也需要修正，给出的点应当是图片正中心的点
	//上方
	if (GetIntersectedPoint(center, originPos, FVector2D(0, 0), FVector2D(screenWidth, 0), m_NavData->realPos))
	{
		return;
	}

	//左侧
	if (GetIntersectedPoint(center, originPos, FVector2D(0, 0), FVector2D(0, screenHeight), m_NavData->realPos))
	{
		return;
	}

	//右侧
	if (GetIntersectedPoint(center, originPos, FVector2D(screenWidth, 0), FVector2D(screenWidth, screenHeight), m_NavData->realPos))
	{
		m_NavData->realPos -= FVector2D(2 * UIHalfWidth, 0);
		return;
	}

	//下方
	GetIntersectedPoint(center, originPos, FVector2D(0, screenHeight), FVector2D(screenWidth, screenHeight), m_NavData->realPos);
	m_NavData->realPos -= FVector2D(0, 2 * UIHalfHeight);
}

UNavData* UNavigationTargetComponent::GetNavData()
{
	return m_NavData;
}
