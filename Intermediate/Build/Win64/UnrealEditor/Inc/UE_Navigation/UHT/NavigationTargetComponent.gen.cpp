// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UE_Navigation/Public/NavigationTargetComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNavigationTargetComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UE_NAVIGATION_API UClass* Z_Construct_UClass_UNavigationTargetComponent();
UE_NAVIGATION_API UClass* Z_Construct_UClass_UNavigationTargetComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_UE_Navigation();
// End Cross Module References

// Begin Class UNavigationTargetComponent
void UNavigationTargetComponent::StaticRegisterNativesUNavigationTargetComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNavigationTargetComponent);
UClass* Z_Construct_UClass_UNavigationTargetComponent_NoRegister()
{
	return UNavigationTargetComponent::StaticClass();
}
struct Z_Construct_UClass_UNavigationTargetComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "NavigationTargetComponent.h" },
		{ "ModuleRelativePath", "Public/NavigationTargetComponent.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNavigationTargetComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UNavigationTargetComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_UE_Navigation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNavigationTargetComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UNavigationTargetComponent_Statics::ClassParams = {
	&UNavigationTargetComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNavigationTargetComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UNavigationTargetComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UNavigationTargetComponent()
{
	if (!Z_Registration_Info_UClass_UNavigationTargetComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNavigationTargetComponent.OuterSingleton, Z_Construct_UClass_UNavigationTargetComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UNavigationTargetComponent.OuterSingleton;
}
template<> UE_NAVIGATION_API UClass* StaticClass<UNavigationTargetComponent>()
{
	return UNavigationTargetComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UNavigationTargetComponent);
UNavigationTargetComponent::~UNavigationTargetComponent() {}
// End Class UNavigationTargetComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE_Navigation_Source_UE_Navigation_Public_NavigationTargetComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UNavigationTargetComponent, UNavigationTargetComponent::StaticClass, TEXT("UNavigationTargetComponent"), &Z_Registration_Info_UClass_UNavigationTargetComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNavigationTargetComponent), 2729737602U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_Navigation_Source_UE_Navigation_Public_NavigationTargetComponent_h_342755463(TEXT("/Script/UE_Navigation"),
	Z_CompiledInDeferFile_FID_UE_Navigation_Source_UE_Navigation_Public_NavigationTargetComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_Navigation_Source_UE_Navigation_Public_NavigationTargetComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
