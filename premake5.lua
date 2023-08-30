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
	cppdialect "C++20"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp"
	}
	
	defines
	{
	
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/glm"
	}

	links
	{
		--"glfw", -- Mirage is a shared library, so it can link a static one
		--"opengl32.lib"
	}

	filter "system:windows"
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
	cppdialect "C++20"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.hpp",
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