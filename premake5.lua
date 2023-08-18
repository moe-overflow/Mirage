workspace "Mirage"
	architecture "x64"

	configurations
	{
		"Debug", 
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" 

IncludeDir = {}
IncludeDir["GLFW"] = "Mirage/vendor/GLFW/include"

include "Mirage/vendor/GLFW"


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
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/glm",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW", -- Mirage is a shared library, so it can link a static one
		"opengl32.lib"
		--"dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++20"
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
		"Mirage/src",
		"Mirage/vendor/glm"
	}

	links
	{
		"Mirage"
	}

	filter "system:windows"
		cppdialect "C++20"
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


include "Mirage/vendor/GLFW"

