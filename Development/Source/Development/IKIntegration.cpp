// Fill out your copyright notice in the Description page of Project Settings.

#include "IKIntegration.h"
#include "Runtime/Core/Public/Misc/Paths.h"
#include "Runtime/Core/Public/HAL/FileManager.h"
#include <string>

// Create instances of ROS needed
KDL::Tree my_tree;
urdf::Model my_model;

// Sets default values
AIKIntegration::AIKIntegration()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AIKIntegration::BeginPlay()
{
	Super::BeginPlay();
	StartupModule();
	GetRobotName();
	CreateTree();
}

// Called every frame
void AIKIntegration::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Create method that parses URDF file into a urdf Model object
void AIKIntegration::StartupModule()
{
	// Grab relative project path for file system and convert to string
	FString RelativeProjPath = FPaths::ProjectDir();
	std::string ProjPath(TCHAR_TO_UTF8(*RelativeProjPath));

	if (!my_model.initFile(ProjPath + "Source/Development/robot.urdf")) {
		UE_LOG(LogTemp, Log, TEXT("Failed to parse urdf file"));
	}
	else {
		UE_LOG(LogTemp, Log, TEXT("Parsed the urdf file"));
	}
}

// Create method that reads robots name from urdf Model
// as a means of demonstrating parser success
void AIKIntegration::GetRobotName()
{
	std::string test = my_model.getName();
	FString modelName(test.c_str());
	UE_LOG(LogTemp, Log, TEXT("Robot is called: %s"), *modelName);
}

// Create method that passes a urdf Model into a KDL tree
void AIKIntegration::CreateTree()
{
	if (!kdl_parser::treeFromUrdfModel(my_model, my_tree)) {
		UE_LOG(LogTemp, Log, TEXT("Failed to construct kdl tree"));
	}
	else {
		UE_LOG(LogTemp, Log, TEXT("Constructed the kdl tree"));

		// List number of segments in tree to demonstrate success of object creation
		int test2 = my_tree.getNrOfSegments();
		FString treeSegments = FString::FromInt(test2);
		UE_LOG(LogTemp, Log, TEXT("Number of segments in tree is: %s"), *treeSegments);

		// From this object, a KDL IK solver could be created..
	}
}
