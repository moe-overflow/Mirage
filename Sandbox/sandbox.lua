project "02_Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	targetname("SandBox")
	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir    ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{wks.location}/Sandbox/src/**.hpp",
		"%{wks.location}/Sandbox/src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Mirage/vendor/spdlog/include",
		"%{wks.location}/Mirage/src",
		"%{wks.location}/Mirage/include",
		"%{wks.location}/Mirage/vendor/glm",
		"%{wks.location}/Mirage/vendor/glfw/include",
		"%{wks.location}/Mirage/vendor/glfw/deps",
		"%{wks.location}/Mirage/vendor/glad/include"
	}

	links
	{
		"01_Mirage"
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
