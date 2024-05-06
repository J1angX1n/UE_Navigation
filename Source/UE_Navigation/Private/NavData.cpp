// Fill out your copyright notice in the Description page of Project Settings.
#include "NavData.h"
#include "Engine/Engine.h"

UNavData::UNavData()
{
	pos_x = 0;
	pos_y = 0;
	angle = 0;
	distance = 0;

	realPos = FVector2D(pos_x, pos_y);

	behind = false;
}

UNavData::~UNavData()
{
}
