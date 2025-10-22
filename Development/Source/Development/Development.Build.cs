// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.IO;

public class Development : ModuleRules
{
    // Define path to Module directory
    private string ModulePath
    {
        get { return ModuleDirectory; }
    }

    // Define path to ThirdParty directory
    private string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty/")); }
    }

    public Development(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true

        // Try to include ROS2 libraries
        Loadros2(Target);
    }

    // Add Include paths and Library paths for ROS libraries required
    public bool Loadros2(ReadOnlyTargetRules Target)
    {
        bool isLibrarySupported = false;

        if ((Target.Platform == UnrealTargetPlatform.Win64) || (Target.Platform == UnrealTargetPlatform.Win32))
        {
            isLibrarySupported = true;

            // Define path to Libraries folder within ThirdParty directory
            string LibrariesPath = Path.Combine(ThirdPartyPath, "ROS2", "Libraries");

            // Add libraries to the project
            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "console_bridge.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "orocos-kdl.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "tinyxml.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "tinyxml2.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "urdf.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "urdfdom_model.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "urdfdom_model_state.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "urdfdom_sensor.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "urdfdom_world.lib"));
        }

        if (isLibrarySupported)
        {
            // Add the path to the Includes folder within the ThirdParty directory
            PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "ROS2", "Includes"));
        }

        Definitions.Add(string.Format("WITH_ROS2_BINDING={0}", isLibrarySupported ? 1 : 0));

        return isLibrarySupported;
    }
}
