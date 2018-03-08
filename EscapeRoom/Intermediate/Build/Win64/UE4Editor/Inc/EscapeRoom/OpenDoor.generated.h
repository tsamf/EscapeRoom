// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ESCAPEROOM_OpenDoor_generated_h
#error "OpenDoor.generated.h already included, missing '#pragma once' in OpenDoor.h"
#endif
#define ESCAPEROOM_OpenDoor_generated_h

#define EscapeRoom_Source_EscapeRoom_OpenDoor_h_11_DELEGATE \
static inline void FDoorEvent_DelegateWrapper(const FMulticastScriptDelegate& DoorEvent) \
{ \
	DoorEvent.ProcessMulticastDelegate<UObject>(NULL); \
}


#define EscapeRoom_Source_EscapeRoom_OpenDoor_h_16_RPC_WRAPPERS
#define EscapeRoom_Source_EscapeRoom_OpenDoor_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define EscapeRoom_Source_EscapeRoom_OpenDoor_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOpenDoor(); \
	friend ESCAPEROOM_API class UClass* Z_Construct_UClass_UOpenDoor(); \
public: \
	DECLARE_CLASS(UOpenDoor, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/EscapeRoom"), NO_API) \
	DECLARE_SERIALIZER(UOpenDoor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define EscapeRoom_Source_EscapeRoom_OpenDoor_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUOpenDoor(); \
	friend ESCAPEROOM_API class UClass* Z_Construct_UClass_UOpenDoor(); \
public: \
	DECLARE_CLASS(UOpenDoor, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/EscapeRoom"), NO_API) \
	DECLARE_SERIALIZER(UOpenDoor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define EscapeRoom_Source_EscapeRoom_OpenDoor_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOpenDoor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOpenDoor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOpenDoor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOpenDoor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOpenDoor(UOpenDoor&&); \
	NO_API UOpenDoor(const UOpenDoor&); \
public:


#define EscapeRoom_Source_EscapeRoom_OpenDoor_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOpenDoor(UOpenDoor&&); \
	NO_API UOpenDoor(const UOpenDoor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOpenDoor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOpenDoor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UOpenDoor)


#define EscapeRoom_Source_EscapeRoom_OpenDoor_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__PressurePlate() { return STRUCT_OFFSET(UOpenDoor, PressurePlate); } \
	FORCEINLINE static uint32 __PPO__TriggerMass() { return STRUCT_OFFSET(UOpenDoor, TriggerMass); }


#define EscapeRoom_Source_EscapeRoom_OpenDoor_h_13_PROLOG
#define EscapeRoom_Source_EscapeRoom_OpenDoor_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	EscapeRoom_Source_EscapeRoom_OpenDoor_h_16_PRIVATE_PROPERTY_OFFSET \
	EscapeRoom_Source_EscapeRoom_OpenDoor_h_16_RPC_WRAPPERS \
	EscapeRoom_Source_EscapeRoom_OpenDoor_h_16_INCLASS \
	EscapeRoom_Source_EscapeRoom_OpenDoor_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define EscapeRoom_Source_EscapeRoom_OpenDoor_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	EscapeRoom_Source_EscapeRoom_OpenDoor_h_16_PRIVATE_PROPERTY_OFFSET \
	EscapeRoom_Source_EscapeRoom_OpenDoor_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	EscapeRoom_Source_EscapeRoom_OpenDoor_h_16_INCLASS_NO_PURE_DECLS \
	EscapeRoom_Source_EscapeRoom_OpenDoor_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID EscapeRoom_Source_EscapeRoom_OpenDoor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
