// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Containers/Array.h"
#include "UObject/Object.h"
#include "NavData.h"

#include "NavigationComponent.generated.h"

class APlayerController;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE_NAVIGATION_API UNavigationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNavigationComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	bool GetShow();
	void SetShow(bool value);

	UFUNCTION(BlueprintCallable)
	TArray<UNavData*> GetAllNavDatas();

	bool DeprojectWorldToScreen(APlayerController const* Player, const FVector& WorldPosition, FVector2D& ScreenPosition, bool bPlayerViewportRelative);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NavComponent")
	bool show;


};
