// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "IKIntegration.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIKIntegration() {}
// Cross Module References
	DEVELOPMENT_API UClass* Z_Construct_UClass_AIKIntegration_NoRegister();
	DEVELOPMENT_API UClass* Z_Construct_UClass_AIKIntegration();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Development();
// End Cross Module References
	void AIKIntegration::StaticRegisterNativesAIKIntegration()
	{
	}
	UClass* Z_Construct_UClass_AIKIntegration_NoRegister()
	{
		return AIKIntegration::StaticClass();
	}
	UClass* Z_Construct_UClass_AIKIntegration()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_Development,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "IKIntegration.h" },
				{ "ModuleRelativePath", "IKIntegration.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AIKIntegration>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AIKIntegration::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				nullptr, 0,
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AIKIntegration, 1871848213);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AIKIntegration(Z_Construct_UClass_AIKIntegration, &AIKIntegration::StaticClass, TEXT("/Script/Development"), TEXT("AIKIntegration"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AIKIntegration);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
