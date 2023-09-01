project "Mirage"
	location "Mirage"
	kind "SharedLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir    ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.hpp",
		"src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}
	
	includedirs
	{
		"%{wks.location}/Mirage/src",
		"%{wks.location}/Mirage/vendor/spdlog/include",
		"%{wks.location}/Mirage/vendor/glm",
		"%{wks.location}/Mirage/vendor/glfw/include"
	}

	links
	{
		"glfw", -- Mirage is a shared library, so it can link a static one
		"opengl32.lib"
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
			--("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
		
	filter "configurations:Debug"
		defines "MIRAGE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "MIRAGE_RELEASE"
		runtime "Release"
		optimize "On"


