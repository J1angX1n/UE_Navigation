// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UE_Navigation/Public/NavData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNavData() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
UE_NAVIGATION_API UClass* Z_Construct_UClass_UNavData();
UE_NAVIGATION_API UClass* Z_Construct_UClass_UNavData_NoRegister();
UPackage* Z_Construct_UPackage__Script_UE_Navigation();
// End Cross Module References

// Begin Class UNavData
void UNavData::StaticRegisterNativesUNavData()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNavData);
UClass* Z_Construct_UClass_UNavData_NoRegister()
{
	return UNavData::StaticClass();
}
struct Z_Construct_UClass_UNavData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "NavData.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/NavData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_pos_x_MetaData[] = {
		{ "Category", "NavData" },
		{ "ModuleRelativePath", "Public/NavData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_pos_y_MetaData[] = {
		{ "Category", "NavData" },
		{ "ModuleRelativePath", "Public/NavData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_angle_MetaData[] = {
		{ "Category", "NavData" },
		{ "ModuleRelativePath", "Public/NavData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_distance_MetaData[] = {
		{ "Category", "NavData" },
		{ "ModuleRelativePath", "Public/NavData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_behind_MetaData[] = {
		{ "Category", "NavData" },
		{ "ModuleRelativePath", "Public/NavData.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDoublePropertyParams NewProp_pos_x;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_pos_y;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_angle;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_distance;
	static void NewProp_behind_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_behind;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNavData>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UNavData_Statics::NewProp_pos_x = { "pos_x", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNavData, pos_x), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_pos_x_MetaData), NewProp_pos_x_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UNavData_Statics::NewProp_pos_y = { "pos_y", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNavData, pos_y), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_pos_y_MetaData), NewProp_pos_y_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UNavData_Statics::NewProp_angle = { "angle", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNavData, angle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_angle_MetaData), NewProp_angle_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UNavData_Statics::NewProp_distance = { "distance", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNavData, distance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_distance_MetaData), NewProp_distance_MetaData) };
void Z_Construct_UClass_UNavData_Statics::NewProp_behind_SetBit(void* Obj)
{
	((UNavData*)Obj)->behind = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UNavData_Statics::NewProp_behind = { "behind", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UNavData), &Z_Construct_UClass_UNavData_Statics::NewProp_behind_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_behind_MetaData), NewProp_behind_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UNavData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavData_Statics::NewProp_pos_x,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavData_Statics::NewProp_pos_y,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavData_Statics::NewProp_angle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavData_Statics::NewProp_distance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavData_Statics::NewProp_behind,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNavData_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UNavData_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_UE_Navigation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNavData_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UNavData_Statics::ClassParams = {
	&UNavData::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UNavData_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UNavData_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNavData_Statics::Class_MetaDataParams), Z_Construct_UClass_UNavData_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UNavData()
{
	if (!Z_Registration_Info_UClass_UNavData.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNavData.OuterSingleton, Z_Construct_UClass_UNavData_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UNavData.OuterSingleton;
}
template<> UE_NAVIGATION_API UClass* StaticClass<UNavData>()
{
	return UNavData::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UNavData);
// End Class UNavData

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE_Navigation_Source_UE_Navigation_Public_NavData_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UNavData, UNavData::StaticClass, TEXT("UNavData"), &Z_Registration_Info_UClass_UNavData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNavData), 554689551U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_Navigation_Source_UE_Navigation_Public_NavData_h_1538028706(TEXT("/Script/UE_Navigation"),
	Z_CompiledInDeferFile_FID_UE_Navigation_Source_UE_Navigation_Public_NavData_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_Navigation_Source_UE_Navigation_Public_NavData_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
