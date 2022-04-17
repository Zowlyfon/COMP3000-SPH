// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class Simulation : ModuleRules
{
	private string ProjectRootPath
	{
		get { return Path.Combine(ModuleDirectory, "../.."); }
	}
	
	public Simulation(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] { "Niagara" });
		
		string CustomCudaLibInclude = "CUDALib/include";
		string CustomCudaLibLib = "CUDALib/lib";
		
		PublicIncludePaths.Add(Path.Combine(ProjectRootPath, CustomCudaLibInclude));
		PublicAdditionalLibraries.Add(Path.Combine(ProjectRootPath, CustomCudaLibLib, "SPH_CUDA.cu.obj"));
		PublicAdditionalLibraries.Add(Path.Combine(ProjectRootPath, CustomCudaLibLib, "SPH_CUDA_UTIL.cu.obj"));

		string CUDAPath = "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.4";
		string CUDAInclude = "include";
		string CUDALib = "lib/x64";
		
		PublicIncludePaths.Add(Path.Combine(CUDAPath, CUDAInclude));
		
		PublicAdditionalLibraries.Add(Path.Combine(CUDAPath, CUDALib, "cudart_static.lib"));

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
