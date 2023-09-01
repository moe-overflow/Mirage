workspace "Mirage"
	architecture "x64"
	configurations{	"Debug", "Release" }
	--startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Mirage/mirage.lua"
include "Sandbox/sandbox.lua"
include "Mirage/vendor/glfw.lua"

