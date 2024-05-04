// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Containers/Array.h"

#include "NavGameInstanceSubsystem.generated.h"

class AActor;

/**
 * 
 */
UCLASS()
class UE_NAVIGATION_API UNavGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UNavGameInstanceSubsystem();
	~UNavGameInstanceSubsystem();

	UFUNCTION(BlueprintCallable)
	TArray<AActor*> GetTargets();

	UFUNCTION(BlueprintCallable)
	bool AddTarget(AActor* actor);

	UFUNCTION(BlueprintCallable)
	int32 GetTargetNum();
	
protected:
	//�洢ָ��Ŀ��
	TArray<AActor*> targets;


};
