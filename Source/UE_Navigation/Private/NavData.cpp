// Fill out your copyright notice in the Description page of Project Settings.
#include "NavData.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/Engine.h"

UNavData::UNavData()
{
	pos_x = 0;
	pos_y = 0;
	angle = 0;
	distance = 0;

	realPos = FVector2D(pos_x, pos_y);

	behind = false;
	status = 0;
}

UNavData::~UNavData()
{
}

void UNavData::GetPosOnScreen(double UIHalfWidth, double UIHalfHeight)
{
	FVector2D originPos = FVector2D(pos_x, pos_y);
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

	if (pos_x >= 0 && pos_x <= screenHalfWidth * 2 && pos_y >= 0 && pos_y <= screenHalfHeight * 2)
	{
		status = 0;
		return;
	}

	if (GetIntersectedPoint(center, originPos, FVector2D(0, 0), FVector2D(screenWidth, 0), realPos))
	{
		status = 1;
		return;
	}

	if (GetIntersectedPoint(center, originPos, FVector2D(0, 0), FVector2D(0, screenHeight), realPos))
	{
		status = 4;
		return;
	}

	if (GetIntersectedPoint(center, originPos, FVector2D(screenWidth, 0), FVector2D(screenWidth, screenHeight), realPos))
	{
		status = 2;
		return;
	}

	GetIntersectedPoint(center, originPos, FVector2D(0, screenHeight), FVector2D(screenWidth, screenHeight), realPos);
	status = 3;
}


bool UNavData::GetIntersectedPoint(FVector2D p1, FVector2D p2, FVector2D p3, FVector2D p4, FVector2D& res)
{
	FVector2D vec1 = p2 - p1, vec2 = p4 - p3;
	FVector2D sub1 = p3 - p1, sub2 = p1 - p3;


	double cross = UKismetMathLibrary::CrossProduct2D(vec1, vec2);

	//平行
	if (cross == 0)
	{
		return false;
	}

	double t = UKismetMathLibrary::CrossProduct2D(p3 - p1, vec2) / cross;
	double u = UKismetMathLibrary::CrossProduct2D(p1 - p3, vec1) / cross;

	//线段不共线但不相交
	if (t < 0 || t>1 || u < 0 || u>1)
	{
		return false;
	}

	res = p1 + t * vec1;
	return true;
}

