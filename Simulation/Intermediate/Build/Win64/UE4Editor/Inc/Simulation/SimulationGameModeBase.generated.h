// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SIMULATION_SimulationGameModeBase_generated_h
#error "SimulationGameModeBase.generated.h already included, missing '#pragma once' in SimulationGameModeBase.h"
#endif
#define SIMULATION_SimulationGameModeBase_generated_h

#define Simulation_Source_Simulation_SimulationGameModeBase_h_15_SPARSE_DATA
#define Simulation_Source_Simulation_SimulationGameModeBase_h_15_RPC_WRAPPERS
#define Simulation_Source_Simulation_SimulationGameModeBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define Simulation_Source_Simulation_SimulationGameModeBase_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASimulationGameModeBase(); \
	friend struct Z_Construct_UClass_ASimulationGameModeBase_Statics; \
public: \
	DECLARE_CLASS(ASimulationGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Simulation"), NO_API) \
	DECLARE_SERIALIZER(ASimulationGameModeBase)


#define Simulation_Source_Simulation_SimulationGameModeBase_h_15_INCLASS \
private: \
	static void StaticRegisterNativesASimulationGameModeBase(); \
	friend struct Z_Construct_UClass_ASimulationGameModeBase_Statics; \
public: \
	DECLARE_CLASS(ASimulationGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Simulation"), NO_API) \
	DECLARE_SERIALIZER(ASimulationGameModeBase)


#define Simulation_Source_Simulation_SimulationGameModeBase_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASimulationGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASimulationGameModeBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASimulationGameModeBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASimulationGameModeBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASimulationGameModeBase(ASimulationGameModeBase&&); \
	NO_API ASimulationGameModeBase(const ASimulationGameModeBase&); \
public:


#define Simulation_Source_Simulation_SimulationGameModeBase_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASimulationGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASimulationGameModeBase(ASimulationGameModeBase&&); \
	NO_API ASimulationGameModeBase(const ASimulationGameModeBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASimulationGameModeBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASimulationGameModeBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASimulationGameModeBase)


#define Simulation_Source_Simulation_SimulationGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET
#define Simulation_Source_Simulation_SimulationGameModeBase_h_12_PROLOG
#define Simulation_Source_Simulation_SimulationGameModeBase_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Simulation_Source_Simulation_SimulationGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET \
	Simulation_Source_Simulation_SimulationGameModeBase_h_15_SPARSE_DATA \
	Simulation_Source_Simulation_SimulationGameModeBase_h_15_RPC_WRAPPERS \
	Simulation_Source_Simulation_SimulationGameModeBase_h_15_INCLASS \
	Simulation_Source_Simulation_SimulationGameModeBase_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Simulation_Source_Simulation_SimulationGameModeBase_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Simulation_Source_Simulation_SimulationGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET \
	Simulation_Source_Simulation_SimulationGameModeBase_h_15_SPARSE_DATA \
	Simulation_Source_Simulation_SimulationGameModeBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Simulation_Source_Simulation_SimulationGameModeBase_h_15_INCLASS_NO_PURE_DECLS \
	Simulation_Source_Simulation_SimulationGameModeBase_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SIMULATION_API UClass* StaticClass<class ASimulationGameModeBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Simulation_Source_Simulation_SimulationGameModeBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
