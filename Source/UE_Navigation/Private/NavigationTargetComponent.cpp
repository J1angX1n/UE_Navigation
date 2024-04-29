// Fill out your copyright notice in the Description page of Project Settings.


#include "NavigationTargetComponent.h"
#include "NavGameInstanceSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Containers/Array.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UNavigationTargetComponent::UNavigationTargetComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

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


// Called every frame
void UNavigationTargetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

