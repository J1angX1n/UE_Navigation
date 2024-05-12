// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NavData.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class UE_NAVIGATION_API UNavData : public UObject
{
	GENERATED_BODY()
	
public:
	UNavData();
	virtual ~UNavData();
	
public:

	UPROPERTY(BlueprintReadWrite)
	double pos_x;
	UPROPERTY(BlueprintReadWrite)
	double pos_y;
	UPROPERTY(BlueprintReadWrite)
	double angle;
	UPROPERTY(BlueprintReadWrite)
	double distance;

	UPROPERTY(BluePrintReadOnly)
	bool behind;

	UPROPERTY(BluePrintReadOnly)
	bool outsideScreen;

	UPROPERTY(BluePrintReadOnly)
	FVector2D realPos;
};
