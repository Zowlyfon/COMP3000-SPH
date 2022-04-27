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
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	NIAGARA_API UClass* Z_Construct_UClass_UNiagaraComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	SIMULATION_API UClass* Z_Construct_UClass_ARenderBox_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ASPHController::execUpdateCollisionBox)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateCollisionBox();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execUpdateSpawnBox)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateSpawnBox();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execUpdateDomainBox)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateDomainBox();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execGetCollisionBoxTransform)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetCollisionBoxTransform();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execSetCollisionBoxTransform)
	{
		P_GET_STRUCT(FVector,Z_Param_Transform);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetCollisionBoxTransform(Z_Param_Transform);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execGetCollisionBoxExtents)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetCollisionBoxExtents();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execSetCollisionBoxExtents)
	{
		P_GET_STRUCT(FVector,Z_Param_Extents);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetCollisionBoxExtents(Z_Param_Extents);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execGetSpawnBoxTransform)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetSpawnBoxTransform();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execSetSpawnBoxTransform)
	{
		P_GET_STRUCT(FVector,Z_Param_Transform);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSpawnBoxTransform(Z_Param_Transform);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execGetSpawnBoxExtents)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetSpawnBoxExtents();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execSetSpawnBoxExtents)
	{
		P_GET_STRUCT(FVector,Z_Param_Extents);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSpawnBoxExtents(Z_Param_Extents);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execGetDomainBoxExtents)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetDomainBoxExtents();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execSetDomainBoxExtents)
	{
		P_GET_STRUCT(FVector,Z_Param_Extents);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetDomainBoxExtents(Z_Param_Extents);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execGetH)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetH();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execSetH)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_newH);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetH(Z_Param_newH);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execGetGravityScale)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetGravityScale();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execSetGravityScale)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_NewGravityScale);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetGravityScale(Z_Param_NewGravityScale);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execGetGasConstant)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetGasConstant();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execSetGasConstant)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_NewGasConstant);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetGasConstant(Z_Param_NewGasConstant);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execGetRestDensity)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetRestDensity();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execSetRestDensity)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_NewRestDensity);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetRestDensity(Z_Param_NewRestDensity);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execGetViscosity)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetViscosity();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execSetViscosity)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_NewViscosity);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetViscosity(Z_Param_NewViscosity);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execGetParticleMass)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetParticleMass();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execSetParticleMass)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_NewMass);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetParticleMass(Z_Param_NewMass);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execGetNumP)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetNumP();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execUnpauseSimulation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UnpauseSimulation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execPauseSimulation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PauseSimulation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execStopSimulation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopSimulation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASPHController::execStartSimulation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StartSimulation();
		P_NATIVE_END;
	}
	void ASPHController::StaticRegisterNativesASPHController()
	{
		UClass* Class = ASPHController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetCollisionBoxExtents", &ASPHController::execGetCollisionBoxExtents },
			{ "GetCollisionBoxTransform", &ASPHController::execGetCollisionBoxTransform },
			{ "GetDomainBoxExtents", &ASPHController::execGetDomainBoxExtents },
			{ "GetGasConstant", &ASPHController::execGetGasConstant },
			{ "GetGravityScale", &ASPHController::execGetGravityScale },
			{ "GetH", &ASPHController::execGetH },
			{ "GetNumP", &ASPHController::execGetNumP },
			{ "GetParticleMass", &ASPHController::execGetParticleMass },
			{ "GetRestDensity", &ASPHController::execGetRestDensity },
			{ "GetSpawnBoxExtents", &ASPHController::execGetSpawnBoxExtents },
			{ "GetSpawnBoxTransform", &ASPHController::execGetSpawnBoxTransform },
			{ "GetViscosity", &ASPHController::execGetViscosity },
			{ "PauseSimulation", &ASPHController::execPauseSimulation },
			{ "SetCollisionBoxExtents", &ASPHController::execSetCollisionBoxExtents },
			{ "SetCollisionBoxTransform", &ASPHController::execSetCollisionBoxTransform },
			{ "SetDomainBoxExtents", &ASPHController::execSetDomainBoxExtents },
			{ "SetGasConstant", &ASPHController::execSetGasConstant },
			{ "SetGravityScale", &ASPHController::execSetGravityScale },
			{ "SetH", &ASPHController::execSetH },
			{ "SetParticleMass", &ASPHController::execSetParticleMass },
			{ "SetRestDensity", &ASPHController::execSetRestDensity },
			{ "SetSpawnBoxExtents", &ASPHController::execSetSpawnBoxExtents },
			{ "SetSpawnBoxTransform", &ASPHController::execSetSpawnBoxTransform },
			{ "SetViscosity", &ASPHController::execSetViscosity },
			{ "StartSimulation", &ASPHController::execStartSimulation },
			{ "StopSimulation", &ASPHController::execStopSimulation },
			{ "UnpauseSimulation", &ASPHController::execUnpauseSimulation },
			{ "UpdateCollisionBox", &ASPHController::execUpdateCollisionBox },
			{ "UpdateDomainBox", &ASPHController::execUpdateDomainBox },
			{ "UpdateSpawnBox", &ASPHController::execUpdateSpawnBox },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASPHController_GetCollisionBoxExtents_Statics
	{
		struct SPHController_eventGetCollisionBoxExtents_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASPHController_GetCollisionBoxExtents_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventGetCollisionBoxExtents_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_GetCollisionBoxExtents_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_GetCollisionBoxExtents_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_GetCollisionBoxExtents_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_GetCollisionBoxExtents_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "GetCollisionBoxExtents", nullptr, nullptr, sizeof(SPHController_eventGetCollisionBoxExtents_Parms), Z_Construct_UFunction_ASPHController_GetCollisionBoxExtents_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetCollisionBoxExtents_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_GetCollisionBoxExtents_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetCollisionBoxExtents_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_GetCollisionBoxExtents()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_GetCollisionBoxExtents_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_GetCollisionBoxTransform_Statics
	{
		struct SPHController_eventGetCollisionBoxTransform_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASPHController_GetCollisionBoxTransform_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventGetCollisionBoxTransform_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_GetCollisionBoxTransform_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_GetCollisionBoxTransform_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_GetCollisionBoxTransform_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_GetCollisionBoxTransform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "GetCollisionBoxTransform", nullptr, nullptr, sizeof(SPHController_eventGetCollisionBoxTransform_Parms), Z_Construct_UFunction_ASPHController_GetCollisionBoxTransform_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetCollisionBoxTransform_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_GetCollisionBoxTransform_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetCollisionBoxTransform_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_GetCollisionBoxTransform()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_GetCollisionBoxTransform_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_GetDomainBoxExtents_Statics
	{
		struct SPHController_eventGetDomainBoxExtents_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASPHController_GetDomainBoxExtents_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventGetDomainBoxExtents_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_GetDomainBoxExtents_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_GetDomainBoxExtents_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_GetDomainBoxExtents_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_GetDomainBoxExtents_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "GetDomainBoxExtents", nullptr, nullptr, sizeof(SPHController_eventGetDomainBoxExtents_Parms), Z_Construct_UFunction_ASPHController_GetDomainBoxExtents_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetDomainBoxExtents_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_GetDomainBoxExtents_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetDomainBoxExtents_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_GetDomainBoxExtents()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_GetDomainBoxExtents_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_GetGasConstant_Statics
	{
		struct SPHController_eventGetGasConstant_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASPHController_GetGasConstant_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventGetGasConstant_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_GetGasConstant_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_GetGasConstant_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_GetGasConstant_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_GetGasConstant_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "GetGasConstant", nullptr, nullptr, sizeof(SPHController_eventGetGasConstant_Parms), Z_Construct_UFunction_ASPHController_GetGasConstant_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetGasConstant_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_GetGasConstant_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetGasConstant_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_GetGasConstant()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_GetGasConstant_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_GetGravityScale_Statics
	{
		struct SPHController_eventGetGravityScale_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASPHController_GetGravityScale_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventGetGravityScale_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_GetGravityScale_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_GetGravityScale_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_GetGravityScale_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_GetGravityScale_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "GetGravityScale", nullptr, nullptr, sizeof(SPHController_eventGetGravityScale_Parms), Z_Construct_UFunction_ASPHController_GetGravityScale_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetGravityScale_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_GetGravityScale_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetGravityScale_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_GetGravityScale()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_GetGravityScale_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_GetH_Statics
	{
		struct SPHController_eventGetH_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASPHController_GetH_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventGetH_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_GetH_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_GetH_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_GetH_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_GetH_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "GetH", nullptr, nullptr, sizeof(SPHController_eventGetH_Parms), Z_Construct_UFunction_ASPHController_GetH_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetH_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_GetH_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetH_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_GetH()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_GetH_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_GetNumP_Statics
	{
		struct SPHController_eventGetNumP_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASPHController_GetNumP_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventGetNumP_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_GetNumP_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_GetNumP_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_GetNumP_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// Getters and Setters\n" },
		{ "ModuleRelativePath", "SPHController.h" },
		{ "ToolTip", "Getters and Setters" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_GetNumP_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "GetNumP", nullptr, nullptr, sizeof(SPHController_eventGetNumP_Parms), Z_Construct_UFunction_ASPHController_GetNumP_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetNumP_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_GetNumP_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetNumP_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_GetNumP()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_GetNumP_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_GetParticleMass_Statics
	{
		struct SPHController_eventGetParticleMass_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASPHController_GetParticleMass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventGetParticleMass_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_GetParticleMass_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_GetParticleMass_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_GetParticleMass_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_GetParticleMass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "GetParticleMass", nullptr, nullptr, sizeof(SPHController_eventGetParticleMass_Parms), Z_Construct_UFunction_ASPHController_GetParticleMass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetParticleMass_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_GetParticleMass_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetParticleMass_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_GetParticleMass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_GetParticleMass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_GetRestDensity_Statics
	{
		struct SPHController_eventGetRestDensity_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASPHController_GetRestDensity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventGetRestDensity_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_GetRestDensity_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_GetRestDensity_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_GetRestDensity_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_GetRestDensity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "GetRestDensity", nullptr, nullptr, sizeof(SPHController_eventGetRestDensity_Parms), Z_Construct_UFunction_ASPHController_GetRestDensity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetRestDensity_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_GetRestDensity_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetRestDensity_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_GetRestDensity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_GetRestDensity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_GetSpawnBoxExtents_Statics
	{
		struct SPHController_eventGetSpawnBoxExtents_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASPHController_GetSpawnBoxExtents_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventGetSpawnBoxExtents_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_GetSpawnBoxExtents_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_GetSpawnBoxExtents_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_GetSpawnBoxExtents_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_GetSpawnBoxExtents_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "GetSpawnBoxExtents", nullptr, nullptr, sizeof(SPHController_eventGetSpawnBoxExtents_Parms), Z_Construct_UFunction_ASPHController_GetSpawnBoxExtents_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetSpawnBoxExtents_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_GetSpawnBoxExtents_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetSpawnBoxExtents_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_GetSpawnBoxExtents()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_GetSpawnBoxExtents_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_GetSpawnBoxTransform_Statics
	{
		struct SPHController_eventGetSpawnBoxTransform_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASPHController_GetSpawnBoxTransform_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventGetSpawnBoxTransform_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_GetSpawnBoxTransform_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_GetSpawnBoxTransform_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_GetSpawnBoxTransform_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_GetSpawnBoxTransform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "GetSpawnBoxTransform", nullptr, nullptr, sizeof(SPHController_eventGetSpawnBoxTransform_Parms), Z_Construct_UFunction_ASPHController_GetSpawnBoxTransform_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetSpawnBoxTransform_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_GetSpawnBoxTransform_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetSpawnBoxTransform_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_GetSpawnBoxTransform()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_GetSpawnBoxTransform_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_GetViscosity_Statics
	{
		struct SPHController_eventGetViscosity_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASPHController_GetViscosity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventGetViscosity_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_GetViscosity_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_GetViscosity_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_GetViscosity_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_GetViscosity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "GetViscosity", nullptr, nullptr, sizeof(SPHController_eventGetViscosity_Parms), Z_Construct_UFunction_ASPHController_GetViscosity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetViscosity_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_GetViscosity_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_GetViscosity_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_GetViscosity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_GetViscosity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_PauseSimulation_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_PauseSimulation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_PauseSimulation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "PauseSimulation", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_PauseSimulation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_PauseSimulation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_PauseSimulation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_PauseSimulation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_SetCollisionBoxExtents_Statics
	{
		struct SPHController_eventSetCollisionBoxExtents_Parms
		{
			FVector Extents;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Extents;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASPHController_SetCollisionBoxExtents_Statics::NewProp_Extents = { "Extents", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventSetCollisionBoxExtents_Parms, Extents), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_SetCollisionBoxExtents_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_SetCollisionBoxExtents_Statics::NewProp_Extents,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_SetCollisionBoxExtents_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_SetCollisionBoxExtents_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "SetCollisionBoxExtents", nullptr, nullptr, sizeof(SPHController_eventSetCollisionBoxExtents_Parms), Z_Construct_UFunction_ASPHController_SetCollisionBoxExtents_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_SetCollisionBoxExtents_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_SetCollisionBoxExtents_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_SetCollisionBoxExtents_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_SetCollisionBoxExtents()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_SetCollisionBoxExtents_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_SetCollisionBoxTransform_Statics
	{
		struct SPHController_eventSetCollisionBoxTransform_Parms
		{
			FVector Transform;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Transform;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASPHController_SetCollisionBoxTransform_Statics::NewProp_Transform = { "Transform", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventSetCollisionBoxTransform_Parms, Transform), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_SetCollisionBoxTransform_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_SetCollisionBoxTransform_Statics::NewProp_Transform,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_SetCollisionBoxTransform_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_SetCollisionBoxTransform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "SetCollisionBoxTransform", nullptr, nullptr, sizeof(SPHController_eventSetCollisionBoxTransform_Parms), Z_Construct_UFunction_ASPHController_SetCollisionBoxTransform_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_SetCollisionBoxTransform_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_SetCollisionBoxTransform_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_SetCollisionBoxTransform_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_SetCollisionBoxTransform()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_SetCollisionBoxTransform_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_SetDomainBoxExtents_Statics
	{
		struct SPHController_eventSetDomainBoxExtents_Parms
		{
			FVector Extents;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Extents;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASPHController_SetDomainBoxExtents_Statics::NewProp_Extents = { "Extents", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventSetDomainBoxExtents_Parms, Extents), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_SetDomainBoxExtents_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_SetDomainBoxExtents_Statics::NewProp_Extents,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_SetDomainBoxExtents_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_SetDomainBoxExtents_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "SetDomainBoxExtents", nullptr, nullptr, sizeof(SPHController_eventSetDomainBoxExtents_Parms), Z_Construct_UFunction_ASPHController_SetDomainBoxExtents_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_SetDomainBoxExtents_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_SetDomainBoxExtents_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_SetDomainBoxExtents_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_SetDomainBoxExtents()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_SetDomainBoxExtents_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_SetGasConstant_Statics
	{
		struct SPHController_eventSetGasConstant_Parms
		{
			float NewGasConstant;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewGasConstant;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASPHController_SetGasConstant_Statics::NewProp_NewGasConstant = { "NewGasConstant", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventSetGasConstant_Parms, NewGasConstant), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_SetGasConstant_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_SetGasConstant_Statics::NewProp_NewGasConstant,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_SetGasConstant_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_SetGasConstant_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "SetGasConstant", nullptr, nullptr, sizeof(SPHController_eventSetGasConstant_Parms), Z_Construct_UFunction_ASPHController_SetGasConstant_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_SetGasConstant_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_SetGasConstant_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_SetGasConstant_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_SetGasConstant()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_SetGasConstant_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_SetGravityScale_Statics
	{
		struct SPHController_eventSetGravityScale_Parms
		{
			float NewGravityScale;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewGravityScale;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASPHController_SetGravityScale_Statics::NewProp_NewGravityScale = { "NewGravityScale", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventSetGravityScale_Parms, NewGravityScale), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_SetGravityScale_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_SetGravityScale_Statics::NewProp_NewGravityScale,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_SetGravityScale_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_SetGravityScale_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "SetGravityScale", nullptr, nullptr, sizeof(SPHController_eventSetGravityScale_Parms), Z_Construct_UFunction_ASPHController_SetGravityScale_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_SetGravityScale_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_SetGravityScale_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_SetGravityScale_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_SetGravityScale()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_SetGravityScale_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_SetH_Statics
	{
		struct SPHController_eventSetH_Parms
		{
			float newH;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_newH;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASPHController_SetH_Statics::NewProp_newH = { "newH", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventSetH_Parms, newH), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_SetH_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_SetH_Statics::NewProp_newH,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_SetH_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_SetH_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "SetH", nullptr, nullptr, sizeof(SPHController_eventSetH_Parms), Z_Construct_UFunction_ASPHController_SetH_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_SetH_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_SetH_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_SetH_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_SetH()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_SetH_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_SetParticleMass_Statics
	{
		struct SPHController_eventSetParticleMass_Parms
		{
			float NewMass;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewMass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASPHController_SetParticleMass_Statics::NewProp_NewMass = { "NewMass", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventSetParticleMass_Parms, NewMass), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_SetParticleMass_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_SetParticleMass_Statics::NewProp_NewMass,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_SetParticleMass_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_SetParticleMass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "SetParticleMass", nullptr, nullptr, sizeof(SPHController_eventSetParticleMass_Parms), Z_Construct_UFunction_ASPHController_SetParticleMass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_SetParticleMass_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_SetParticleMass_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_SetParticleMass_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_SetParticleMass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_SetParticleMass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_SetRestDensity_Statics
	{
		struct SPHController_eventSetRestDensity_Parms
		{
			float NewRestDensity;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewRestDensity;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASPHController_SetRestDensity_Statics::NewProp_NewRestDensity = { "NewRestDensity", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventSetRestDensity_Parms, NewRestDensity), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_SetRestDensity_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_SetRestDensity_Statics::NewProp_NewRestDensity,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_SetRestDensity_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_SetRestDensity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "SetRestDensity", nullptr, nullptr, sizeof(SPHController_eventSetRestDensity_Parms), Z_Construct_UFunction_ASPHController_SetRestDensity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_SetRestDensity_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_SetRestDensity_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_SetRestDensity_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_SetRestDensity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_SetRestDensity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_SetSpawnBoxExtents_Statics
	{
		struct SPHController_eventSetSpawnBoxExtents_Parms
		{
			FVector Extents;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Extents;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASPHController_SetSpawnBoxExtents_Statics::NewProp_Extents = { "Extents", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventSetSpawnBoxExtents_Parms, Extents), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_SetSpawnBoxExtents_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_SetSpawnBoxExtents_Statics::NewProp_Extents,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_SetSpawnBoxExtents_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_SetSpawnBoxExtents_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "SetSpawnBoxExtents", nullptr, nullptr, sizeof(SPHController_eventSetSpawnBoxExtents_Parms), Z_Construct_UFunction_ASPHController_SetSpawnBoxExtents_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_SetSpawnBoxExtents_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_SetSpawnBoxExtents_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_SetSpawnBoxExtents_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_SetSpawnBoxExtents()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_SetSpawnBoxExtents_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_SetSpawnBoxTransform_Statics
	{
		struct SPHController_eventSetSpawnBoxTransform_Parms
		{
			FVector Transform;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Transform;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASPHController_SetSpawnBoxTransform_Statics::NewProp_Transform = { "Transform", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventSetSpawnBoxTransform_Parms, Transform), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_SetSpawnBoxTransform_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_SetSpawnBoxTransform_Statics::NewProp_Transform,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_SetSpawnBoxTransform_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_SetSpawnBoxTransform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "SetSpawnBoxTransform", nullptr, nullptr, sizeof(SPHController_eventSetSpawnBoxTransform_Parms), Z_Construct_UFunction_ASPHController_SetSpawnBoxTransform_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_SetSpawnBoxTransform_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_SetSpawnBoxTransform_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_SetSpawnBoxTransform_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_SetSpawnBoxTransform()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_SetSpawnBoxTransform_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_SetViscosity_Statics
	{
		struct SPHController_eventSetViscosity_Parms
		{
			float NewViscosity;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewViscosity;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASPHController_SetViscosity_Statics::NewProp_NewViscosity = { "NewViscosity", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SPHController_eventSetViscosity_Parms, NewViscosity), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASPHController_SetViscosity_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASPHController_SetViscosity_Statics::NewProp_NewViscosity,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_SetViscosity_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_SetViscosity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "SetViscosity", nullptr, nullptr, sizeof(SPHController_eventSetViscosity_Parms), Z_Construct_UFunction_ASPHController_SetViscosity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_SetViscosity_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_SetViscosity_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_SetViscosity_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_SetViscosity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_SetViscosity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_StartSimulation_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_StartSimulation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_StartSimulation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "StartSimulation", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_StartSimulation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_StartSimulation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_StartSimulation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_StartSimulation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_StopSimulation_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_StopSimulation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_StopSimulation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "StopSimulation", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_StopSimulation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_StopSimulation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_StopSimulation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_StopSimulation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_UnpauseSimulation_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_UnpauseSimulation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_UnpauseSimulation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "UnpauseSimulation", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_UnpauseSimulation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_UnpauseSimulation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_UnpauseSimulation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_UnpauseSimulation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_UpdateCollisionBox_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_UpdateCollisionBox_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_UpdateCollisionBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "UpdateCollisionBox", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_UpdateCollisionBox_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_UpdateCollisionBox_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_UpdateCollisionBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_UpdateCollisionBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_UpdateDomainBox_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_UpdateDomainBox_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_UpdateDomainBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "UpdateDomainBox", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_UpdateDomainBox_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_UpdateDomainBox_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_UpdateDomainBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_UpdateDomainBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASPHController_UpdateSpawnBox_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASPHController_UpdateSpawnBox_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASPHController_UpdateSpawnBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASPHController, nullptr, "UpdateSpawnBox", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASPHController_UpdateSpawnBox_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASPHController_UpdateSpawnBox_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASPHController_UpdateSpawnBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASPHController_UpdateSpawnBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ASPHController_NoRegister()
	{
		return ASPHController::StaticClass();
	}
	struct Z_Construct_UClass_ASPHController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SimStepPerFrame_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_SimStepPerFrame;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SimShouldTick_MetaData[];
#endif
		static void NewProp_SimShouldTick_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_SimShouldTick;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SimStarted_MetaData[];
#endif
		static void NewProp_SimStarted_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_SimStarted;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NiagaraComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NiagaraComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpawnBoxClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_SpawnBoxClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DomainBoxClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_DomainBoxClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CollisionBoxClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_CollisionBoxClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASPHController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Simulation,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASPHController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASPHController_GetCollisionBoxExtents, "GetCollisionBoxExtents" }, // 224796144
		{ &Z_Construct_UFunction_ASPHController_GetCollisionBoxTransform, "GetCollisionBoxTransform" }, // 37135929
		{ &Z_Construct_UFunction_ASPHController_GetDomainBoxExtents, "GetDomainBoxExtents" }, // 2212057210
		{ &Z_Construct_UFunction_ASPHController_GetGasConstant, "GetGasConstant" }, // 2986450142
		{ &Z_Construct_UFunction_ASPHController_GetGravityScale, "GetGravityScale" }, // 1856009162
		{ &Z_Construct_UFunction_ASPHController_GetH, "GetH" }, // 2740101835
		{ &Z_Construct_UFunction_ASPHController_GetNumP, "GetNumP" }, // 2297906222
		{ &Z_Construct_UFunction_ASPHController_GetParticleMass, "GetParticleMass" }, // 1666893586
		{ &Z_Construct_UFunction_ASPHController_GetRestDensity, "GetRestDensity" }, // 4036866951
		{ &Z_Construct_UFunction_ASPHController_GetSpawnBoxExtents, "GetSpawnBoxExtents" }, // 2198604422
		{ &Z_Construct_UFunction_ASPHController_GetSpawnBoxTransform, "GetSpawnBoxTransform" }, // 3001030939
		{ &Z_Construct_UFunction_ASPHController_GetViscosity, "GetViscosity" }, // 1573770104
		{ &Z_Construct_UFunction_ASPHController_PauseSimulation, "PauseSimulation" }, // 745661021
		{ &Z_Construct_UFunction_ASPHController_SetCollisionBoxExtents, "SetCollisionBoxExtents" }, // 1365036906
		{ &Z_Construct_UFunction_ASPHController_SetCollisionBoxTransform, "SetCollisionBoxTransform" }, // 4128195613
		{ &Z_Construct_UFunction_ASPHController_SetDomainBoxExtents, "SetDomainBoxExtents" }, // 1612921183
		{ &Z_Construct_UFunction_ASPHController_SetGasConstant, "SetGasConstant" }, // 59945306
		{ &Z_Construct_UFunction_ASPHController_SetGravityScale, "SetGravityScale" }, // 4156756325
		{ &Z_Construct_UFunction_ASPHController_SetH, "SetH" }, // 3873607617
		{ &Z_Construct_UFunction_ASPHController_SetParticleMass, "SetParticleMass" }, // 4266264640
		{ &Z_Construct_UFunction_ASPHController_SetRestDensity, "SetRestDensity" }, // 1414332073
		{ &Z_Construct_UFunction_ASPHController_SetSpawnBoxExtents, "SetSpawnBoxExtents" }, // 3899406941
		{ &Z_Construct_UFunction_ASPHController_SetSpawnBoxTransform, "SetSpawnBoxTransform" }, // 1078888743
		{ &Z_Construct_UFunction_ASPHController_SetViscosity, "SetViscosity" }, // 1412093878
		{ &Z_Construct_UFunction_ASPHController_StartSimulation, "StartSimulation" }, // 162425069
		{ &Z_Construct_UFunction_ASPHController_StopSimulation, "StopSimulation" }, // 2376273210
		{ &Z_Construct_UFunction_ASPHController_UnpauseSimulation, "UnpauseSimulation" }, // 3837249280
		{ &Z_Construct_UFunction_ASPHController_UpdateCollisionBox, "UpdateCollisionBox" }, // 3980403020
		{ &Z_Construct_UFunction_ASPHController_UpdateDomainBox, "UpdateDomainBox" }, // 3009309536
		{ &Z_Construct_UFunction_ASPHController_UpdateSpawnBox, "UpdateSpawnBox" }, // 3545306901
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASPHController_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SPHController.h" },
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASPHController_Statics::NewProp_SimStepPerFrame_MetaData[] = {
		{ "Category", "SPHController" },
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ASPHController_Statics::NewProp_SimStepPerFrame = { "SimStepPerFrame", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASPHController, SimStepPerFrame), METADATA_PARAMS(Z_Construct_UClass_ASPHController_Statics::NewProp_SimStepPerFrame_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASPHController_Statics::NewProp_SimStepPerFrame_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASPHController_Statics::NewProp_SimShouldTick_MetaData[] = {
		{ "Category", "SPHController" },
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	void Z_Construct_UClass_ASPHController_Statics::NewProp_SimShouldTick_SetBit(void* Obj)
	{
		((ASPHController*)Obj)->SimShouldTick = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASPHController_Statics::NewProp_SimShouldTick = { "SimShouldTick", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASPHController), &Z_Construct_UClass_ASPHController_Statics::NewProp_SimShouldTick_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASPHController_Statics::NewProp_SimShouldTick_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASPHController_Statics::NewProp_SimShouldTick_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASPHController_Statics::NewProp_SimStarted_MetaData[] = {
		{ "Category", "SPHController" },
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	void Z_Construct_UClass_ASPHController_Statics::NewProp_SimStarted_SetBit(void* Obj)
	{
		((ASPHController*)Obj)->SimStarted = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASPHController_Statics::NewProp_SimStarted = { "SimStarted", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASPHController), &Z_Construct_UClass_ASPHController_Statics::NewProp_SimStarted_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASPHController_Statics::NewProp_SimStarted_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASPHController_Statics::NewProp_SimStarted_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASPHController_Statics::NewProp_NiagaraComponent_MetaData[] = {
		{ "Category", "SPHController" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASPHController_Statics::NewProp_NiagaraComponent = { "NiagaraComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASPHController, NiagaraComponent), Z_Construct_UClass_UNiagaraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASPHController_Statics::NewProp_NiagaraComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASPHController_Statics::NewProp_NiagaraComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASPHController_Statics::NewProp_SpawnBoxClass_MetaData[] = {
		{ "Category", "SPHController" },
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASPHController_Statics::NewProp_SpawnBoxClass = { "SpawnBoxClass", nullptr, (EPropertyFlags)0x0014000000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASPHController, SpawnBoxClass), Z_Construct_UClass_ARenderBox_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ASPHController_Statics::NewProp_SpawnBoxClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASPHController_Statics::NewProp_SpawnBoxClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASPHController_Statics::NewProp_DomainBoxClass_MetaData[] = {
		{ "Category", "SPHController" },
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASPHController_Statics::NewProp_DomainBoxClass = { "DomainBoxClass", nullptr, (EPropertyFlags)0x0014000000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASPHController, DomainBoxClass), Z_Construct_UClass_ARenderBox_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ASPHController_Statics::NewProp_DomainBoxClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASPHController_Statics::NewProp_DomainBoxClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASPHController_Statics::NewProp_CollisionBoxClass_MetaData[] = {
		{ "Category", "SPHController" },
		{ "ModuleRelativePath", "SPHController.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASPHController_Statics::NewProp_CollisionBoxClass = { "CollisionBoxClass", nullptr, (EPropertyFlags)0x0014000000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASPHController, CollisionBoxClass), Z_Construct_UClass_ARenderBox_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ASPHController_Statics::NewProp_CollisionBoxClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASPHController_Statics::NewProp_CollisionBoxClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASPHController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASPHController_Statics::NewProp_SimStepPerFrame,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASPHController_Statics::NewProp_SimShouldTick,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASPHController_Statics::NewProp_SimStarted,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASPHController_Statics::NewProp_NiagaraComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASPHController_Statics::NewProp_SpawnBoxClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASPHController_Statics::NewProp_DomainBoxClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASPHController_Statics::NewProp_CollisionBoxClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASPHController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASPHController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASPHController_Statics::ClassParams = {
		&ASPHController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASPHController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASPHController_Statics::PropPointers),
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
	IMPLEMENT_CLASS(ASPHController, 55614283);
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
