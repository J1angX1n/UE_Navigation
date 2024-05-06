// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UE_Navigation/Public/NavGameInstanceSubsystem.h"
#include "Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNavGameInstanceSubsystem() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
UE_NAVIGATION_API UClass* Z_Construct_UClass_UNavGameInstanceSubsystem();
UE_NAVIGATION_API UClass* Z_Construct_UClass_UNavGameInstanceSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_UE_Navigation();
// End Cross Module References

// Begin Class UNavGameInstanceSubsystem Function AddTarget
struct Z_Construct_UFunction_UNavGameInstanceSubsystem_AddTarget_Statics
{
	struct NavGameInstanceSubsystem_eventAddTarget_Parms
	{
		AActor* actor;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/NavGameInstanceSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_actor;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UNavGameInstanceSubsystem_AddTarget_Statics::NewProp_actor = { "actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavGameInstanceSubsystem_eventAddTarget_Parms, actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UNavGameInstanceSubsystem_AddTarget_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((NavGameInstanceSubsystem_eventAddTarget_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UNavGameInstanceSubsystem_AddTarget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NavGameInstanceSubsystem_eventAddTarget_Parms), &Z_Construct_UFunction_UNavGameInstanceSubsystem_AddTarget_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UNavGameInstanceSubsystem_AddTarget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavGameInstanceSubsystem_AddTarget_Statics::NewProp_actor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavGameInstanceSubsystem_AddTarget_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavGameInstanceSubsystem_AddTarget_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNavGameInstanceSubsystem_AddTarget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UNavGameInstanceSubsystem, nullptr, "AddTarget", nullptr, nullptr, Z_Construct_UFunction_UNavGameInstanceSubsystem_AddTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UNavGameInstanceSubsystem_AddTarget_Statics::PropPointers), sizeof(Z_Construct_UFunction_UNavGameInstanceSubsystem_AddTarget_Statics::NavGameInstanceSubsystem_eventAddTarget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavGameInstanceSubsystem_AddTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNavGameInstanceSubsystem_AddTarget_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UNavGameInstanceSubsystem_AddTarget_Statics::NavGameInstanceSubsystem_eventAddTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UNavGameInstanceSubsystem_AddTarget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNavGameInstanceSubsystem_AddTarget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UNavGameInstanceSubsystem::execAddTarget)
{
	P_GET_OBJECT(AActor,Z_Param_actor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->AddTarget(Z_Param_actor);
	P_NATIVE_END;
}
// End Class UNavGameInstanceSubsystem Function AddTarget

// Begin Class UNavGameInstanceSubsystem Function GetTargetNum
struct Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargetNum_Statics
{
	struct NavGameInstanceSubsystem_eventGetTargetNum_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/NavGameInstanceSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargetNum_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavGameInstanceSubsystem_eventGetTargetNum_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargetNum_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargetNum_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargetNum_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargetNum_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UNavGameInstanceSubsystem, nullptr, "GetTargetNum", nullptr, nullptr, Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargetNum_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargetNum_Statics::PropPointers), sizeof(Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargetNum_Statics::NavGameInstanceSubsystem_eventGetTargetNum_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargetNum_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargetNum_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargetNum_Statics::NavGameInstanceSubsystem_eventGetTargetNum_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargetNum()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargetNum_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UNavGameInstanceSubsystem::execGetTargetNum)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetTargetNum();
	P_NATIVE_END;
}
// End Class UNavGameInstanceSubsystem Function GetTargetNum

// Begin Class UNavGameInstanceSubsystem Function GetTargets
struct Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargets_Statics
{
	struct NavGameInstanceSubsystem_eventGetTargets_Parms
	{
		TArray<AActor*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/NavGameInstanceSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargets_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargets_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavGameInstanceSubsystem_eventGetTargets_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargets_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargets_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargets_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargets_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargets_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UNavGameInstanceSubsystem, nullptr, "GetTargets", nullptr, nullptr, Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargets_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargets_Statics::PropPointers), sizeof(Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargets_Statics::NavGameInstanceSubsystem_eventGetTargets_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargets_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargets_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargets_Statics::NavGameInstanceSubsystem_eventGetTargets_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargets_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UNavGameInstanceSubsystem::execGetTargets)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<AActor*>*)Z_Param__Result=P_THIS->GetTargets();
	P_NATIVE_END;
}
// End Class UNavGameInstanceSubsystem Function GetTargets

// Begin Class UNavGameInstanceSubsystem
void UNavGameInstanceSubsystem::StaticRegisterNativesUNavGameInstanceSubsystem()
{
	UClass* Class = UNavGameInstanceSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AddTarget", &UNavGameInstanceSubsystem::execAddTarget },
		{ "GetTargetNum", &UNavGameInstanceSubsystem::execGetTargetNum },
		{ "GetTargets", &UNavGameInstanceSubsystem::execGetTargets },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNavGameInstanceSubsystem);
UClass* Z_Construct_UClass_UNavGameInstanceSubsystem_NoRegister()
{
	return UNavGameInstanceSubsystem::StaticClass();
}
struct Z_Construct_UClass_UNavGameInstanceSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "NavGameInstanceSubsystem.h" },
		{ "ModuleRelativePath", "Public/NavGameInstanceSubsystem.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UNavGameInstanceSubsystem_AddTarget, "AddTarget" }, // 73433366
		{ &Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargetNum, "GetTargetNum" }, // 3108824930
		{ &Z_Construct_UFunction_UNavGameInstanceSubsystem_GetTargets, "GetTargets" }, // 2454055133
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNavGameInstanceSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UNavGameInstanceSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_UE_Navigation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNavGameInstanceSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UNavGameInstanceSubsystem_Statics::ClassParams = {
	&UNavGameInstanceSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNavGameInstanceSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UNavGameInstanceSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UNavGameInstanceSubsystem()
{
	if (!Z_Registration_Info_UClass_UNavGameInstanceSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNavGameInstanceSubsystem.OuterSingleton, Z_Construct_UClass_UNavGameInstanceSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UNavGameInstanceSubsystem.OuterSingleton;
}
template<> UE_NAVIGATION_API UClass* StaticClass<UNavGameInstanceSubsystem>()
{
	return UNavGameInstanceSubsystem::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UNavGameInstanceSubsystem);
// End Class UNavGameInstanceSubsystem

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE_Navigation_Source_UE_Navigation_Public_NavGameInstanceSubsystem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UNavGameInstanceSubsystem, UNavGameInstanceSubsystem::StaticClass, TEXT("UNavGameInstanceSubsystem"), &Z_Registration_Info_UClass_UNavGameInstanceSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNavGameInstanceSubsystem), 442049548U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_Navigation_Source_UE_Navigation_Public_NavGameInstanceSubsystem_h_1081289177(TEXT("/Script/UE_Navigation"),
	Z_CompiledInDeferFile_FID_UE_Navigation_Source_UE_Navigation_Public_NavGameInstanceSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_Navigation_Source_UE_Navigation_Public_NavGameInstanceSubsystem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
