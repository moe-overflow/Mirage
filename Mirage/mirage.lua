project "01_Mirage"
	location "Mirage"
	kind "SharedLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	targetname ("Mirage")
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
		"%{wks.location}/Mirage/vendor/glfw/include",
		"%{wks.location}/Mirage/vendor/glfw/deps",
		"%{wks.location}/Mirage/vendor/glad/include",
	}

	libdirs
	{
		"%{wks.location}/Mirage/bin/Debug-windows-x86_64/glad",
		"%{wks.location}/Mirage/bin/Debug-windows-x86_64/glfw"
	}

	links --reference
	{
		-- Mirage is a shared library, so it can link static ones
		"03_glfw",
		"04_glad", 
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
			--%{cfg.buildtarget.relpath} 
			--("{COPY} %{wks.location}/bin/" .. outputdir .. "/Sandbox") 
			("{COPY} %{wks.location}/bin/Debug-windows-x86_64/01_Mirage/Mirage.dll %{wks.location}/bin/Debug-windows-x86_64/02_Sandbox")		
		}
		
	filter "configurations:Debug"
		defines "MIRAGE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "MIRAGE_RELEASE"
		runtime "Release"
		optimize "On"


