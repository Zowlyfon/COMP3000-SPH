// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Simulation/RenderBox.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRenderBox() {}
// Cross Module References
	SIMULATION_API UClass* Z_Construct_UClass_ARenderBox_NoRegister();
	SIMULATION_API UClass* Z_Construct_UClass_ARenderBox();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Simulation();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FBox();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ARenderBox::execToFBox)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FBox*)Z_Param__Result=P_THIS->ToFBox();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ARenderBox::execUpdateBoxLocation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateBoxLocation();
		P_NATIVE_END;
	}
	void ARenderBox::StaticRegisterNativesARenderBox()
	{
		UClass* Class = ARenderBox::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ToFBox", &ARenderBox::execToFBox },
			{ "UpdateBoxLocation", &ARenderBox::execUpdateBoxLocation },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ARenderBox_ToFBox_Statics
	{
		struct RenderBox_eventToFBox_Parms
		{
			FBox ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ARenderBox_ToFBox_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RenderBox_eventToFBox_Parms, ReturnValue), Z_Construct_UScriptStruct_FBox, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ARenderBox_ToFBox_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARenderBox_ToFBox_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ARenderBox_ToFBox_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "RenderBox.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ARenderBox_ToFBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ARenderBox, nullptr, "ToFBox", nullptr, nullptr, sizeof(RenderBox_eventToFBox_Parms), Z_Construct_UFunction_ARenderBox_ToFBox_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ARenderBox_ToFBox_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ARenderBox_ToFBox_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ARenderBox_ToFBox_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ARenderBox_ToFBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ARenderBox_ToFBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ARenderBox_UpdateBoxLocation_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ARenderBox_UpdateBoxLocation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "RenderBox.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ARenderBox_UpdateBoxLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ARenderBox, nullptr, "UpdateBoxLocation", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ARenderBox_UpdateBoxLocation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ARenderBox_UpdateBoxLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ARenderBox_UpdateBoxLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ARenderBox_UpdateBoxLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ARenderBox_NoRegister()
	{
		return ARenderBox::StaticClass();
	}
	struct Z_Construct_UClass_ARenderBox_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BoxStart_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_BoxStart;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BoxEnd_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_BoxEnd;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BoxExtents_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_BoxExtents;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BoxTransform_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_BoxTransform;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BoxMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BoxMesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARenderBox_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Simulation,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ARenderBox_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ARenderBox_ToFBox, "ToFBox" }, // 3926550321
		{ &Z_Construct_UFunction_ARenderBox_UpdateBoxLocation, "UpdateBoxLocation" }, // 2857428953
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARenderBox_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "RenderBox.h" },
		{ "ModuleRelativePath", "RenderBox.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxStart_MetaData[] = {
		{ "Category", "RenderBox" },
		{ "ModuleRelativePath", "RenderBox.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxStart = { "BoxStart", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARenderBox, BoxStart), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxStart_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxStart_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxEnd_MetaData[] = {
		{ "Category", "RenderBox" },
		{ "ModuleRelativePath", "RenderBox.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxEnd = { "BoxEnd", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARenderBox, BoxEnd), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxEnd_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxEnd_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxExtents_MetaData[] = {
		{ "Category", "RenderBox" },
		{ "ModuleRelativePath", "RenderBox.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxExtents = { "BoxExtents", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARenderBox, BoxExtents), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxExtents_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxExtents_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxTransform_MetaData[] = {
		{ "Category", "RenderBox" },
		{ "ModuleRelativePath", "RenderBox.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxTransform = { "BoxTransform", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARenderBox, BoxTransform), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxTransform_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxTransform_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxMesh_MetaData[] = {
		{ "Category", "RenderBox" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "RenderBox.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxMesh = { "BoxMesh", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARenderBox, BoxMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxMesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ARenderBox_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxStart,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxEnd,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxExtents,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxTransform,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARenderBox_Statics::NewProp_BoxMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARenderBox_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARenderBox>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ARenderBox_Statics::ClassParams = {
		&ARenderBox::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ARenderBox_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ARenderBox_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ARenderBox_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ARenderBox_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ARenderBox()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ARenderBox_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ARenderBox, 1737171207);
	template<> SIMULATION_API UClass* StaticClass<ARenderBox>()
	{
		return ARenderBox::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARenderBox(Z_Construct_UClass_ARenderBox, &ARenderBox::StaticClass, TEXT("/Script/Simulation"), TEXT("ARenderBox"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARenderBox);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
