// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "NavigationTargetComponent.generated.h"


class UNavData;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE_NAVIGATION_API UNavigationTargetComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNavigationTargetComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	static bool GetIntersectedPoint(FVector2D p1, FVector2D p2, FVector2D p3, FVector2D p4, FVector2D& res);

	//改自FSceneView::ProjectWorldToScreen
	bool ProjectWorldToScreen(const FVector& WorldPosition, const FIntRect& ViewRect, const FMatrix& ViewProjectionMatrix, FVector2D& out_ScreenPos, bool bShouldCalcOutsideViewPosition = false);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void UpdateScreenPosition();

	//在UE基础上稍加修改的世界坐标转屏幕坐标函数，可以处理坐标在身后的情况
	bool DeprojectWorldToScreen(APlayerController const* Player, const FVector& WorldPosition, FVector2D& ScreenPosition, bool bPlayerViewportRelative);

	void GetPosOnScreen(double UIHalfWidth = 0, double UIHalfHeight = 0);

	UNavData* GetNavData();

	void SetDiff(double value) { Diff = value; }
	double GetDiff() { return Diff; }

protected:
	UNavData* m_NavData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NavTarget")
	double Diff;
};
