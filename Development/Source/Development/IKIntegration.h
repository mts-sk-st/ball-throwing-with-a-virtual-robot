// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
// Link ROS library headers
#include "../../ThirdParty/ROS2/Includes/urdf/model.h"
#include "../../ThirdParty/ROS2/Includes/kdl/tree.hpp"
#include "kdl_parser.hpp"
#include "IKIntegration.generated.h"

UCLASS()
class DEVELOPMENT_API AIKIntegration : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AIKIntegration();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Define developed functions
	void StartupModule();
	void GetRobotName();
	void CreateTree();
};
