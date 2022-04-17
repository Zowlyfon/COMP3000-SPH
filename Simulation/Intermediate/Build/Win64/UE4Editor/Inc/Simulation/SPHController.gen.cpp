// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Simulation/SPHController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSPHController() {}
// Cross Module References
	SIMULATION_API UClass* Z_Construct_UClass_ASPHController_NoRegister();
	SIMULATION_API UClass* Z_Construct_UClass_ASPHController();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Simulation();
// End Cross Module References
	void ASPHController::StaticRegisterNativesASPHController()
	{
	}
	UClass* Z_Construct_UClass_ASPHController_NoRegister()
	{
		return ASPHController::StaticClass();
	}
	struct Z_Construct_UClass_ASPHController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASPHController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Simulation,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASPHController_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SPHController.h" },
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASPHController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASPHController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASPHController_Statics::ClassParams = {
		&ASPHController::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASPHController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASPHController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASPHController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASPHController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASPHController, 3969844648);
	template<> SIMULATION_API UClass* StaticClass<ASPHController>()
	{
		return ASPHController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASPHController(Z_Construct_UClass_ASPHController, &ASPHController::StaticClass, TEXT("/Script/Simulation"), TEXT("ASPHController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASPHController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
