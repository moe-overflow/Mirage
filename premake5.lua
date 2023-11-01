workspace "Mirage"
	architecture "x64"
	configurations{	"Debug", "Release" }
	startproject "02_Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Mirage/vendor/glad.lua"
include "Mirage/vendor/glfw.lua"
include "Mirage/mirage.lua"
include "Sandbox/sandbox.lua"


