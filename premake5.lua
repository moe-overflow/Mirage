workspace "Mirage"
	architecture "x64"

	configurations
	{
		"Debug", 
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" 

project "Mirage"
	location "Mirage"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		

		defines
		{
			"MIRAGE_PLATFORM_WINDOWS",
			"MIRAGE_BUILD_DLL"
		}

		-- automating the process of copying the generated dll of the core engine to client application
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
		
	filter "configurations:Debug"
		defines "MIRAGE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MIRAGE_RELEASE"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Mirage/vendor/spdlog/include",
		"Mirage/src"
	}

	links
	{
		"Mirage"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MIRAGE_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "MIRAGE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MIRAGE_RELEASE"
		optimize "On"
	