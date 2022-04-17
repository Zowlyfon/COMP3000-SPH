// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FBox;
#ifdef SIMULATION_RenderBox_generated_h
#error "RenderBox.generated.h already included, missing '#pragma once' in RenderBox.h"
#endif
#define SIMULATION_RenderBox_generated_h

#define Simulation_Source_Simulation_RenderBox_h_12_SPARSE_DATA
#define Simulation_Source_Simulation_RenderBox_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execToFBox); \
	DECLARE_FUNCTION(execUpdateBoxLocation);


#define Simulation_Source_Simulation_RenderBox_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execToFBox); \
	DECLARE_FUNCTION(execUpdateBoxLocation);


#define Simulation_Source_Simulation_RenderBox_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARenderBox(); \
	friend struct Z_Construct_UClass_ARenderBox_Statics; \
public: \
	DECLARE_CLASS(ARenderBox, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Simulation"), NO_API) \
	DECLARE_SERIALIZER(ARenderBox)


#define Simulation_Source_Simulation_RenderBox_h_12_INCLASS \
private: \
	static void StaticRegisterNativesARenderBox(); \
	friend struct Z_Construct_UClass_ARenderBox_Statics; \
public: \
	DECLARE_CLASS(ARenderBox, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Simulation"), NO_API) \
	DECLARE_SERIALIZER(ARenderBox)


#define Simulation_Source_Simulation_RenderBox_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARenderBox(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARenderBox) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARenderBox); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARenderBox); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARenderBox(ARenderBox&&); \
	NO_API ARenderBox(const ARenderBox&); \
public:


#define Simulation_Source_Simulation_RenderBox_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARenderBox(ARenderBox&&); \
	NO_API ARenderBox(const ARenderBox&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARenderBox); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARenderBox); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ARenderBox)


#define Simulation_Source_Simulation_RenderBox_h_12_PRIVATE_PROPERTY_OFFSET
#define Simulation_Source_Simulation_RenderBox_h_9_PROLOG
#define Simulation_Source_Simulation_RenderBox_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Simulation_Source_Simulation_RenderBox_h_12_PRIVATE_PROPERTY_OFFSET \
	Simulation_Source_Simulation_RenderBox_h_12_SPARSE_DATA \
	Simulation_Source_Simulation_RenderBox_h_12_RPC_WRAPPERS \
	Simulation_Source_Simulation_RenderBox_h_12_INCLASS \
	Simulation_Source_Simulation_RenderBox_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Simulation_Source_Simulation_RenderBox_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Simulation_Source_Simulation_RenderBox_h_12_PRIVATE_PROPERTY_OFFSET \
	Simulation_Source_Simulation_RenderBox_h_12_SPARSE_DATA \
	Simulation_Source_Simulation_RenderBox_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	Simulation_Source_Simulation_RenderBox_h_12_INCLASS_NO_PURE_DECLS \
	Simulation_Source_Simulation_RenderBox_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SIMULATION_API UClass* StaticClass<class ARenderBox>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Simulation_Source_Simulation_RenderBox_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
