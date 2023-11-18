workspace "Mirage"
	architecture "x64"
	configurations{	"Debug", "Release" }
	startproject "02_Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Mirage/vendor/glad.lua"
include "Mirage/vendor/glfw.lua"
include "Mirage/mirage.lua"
include "Sandbox/sandbox.lua"




 --[[
	
 if _ACTION == 'clean' then
	os.rmdir('bin')
	os.rmdir('bin-int')
	os.remove('*.sln')
	os.remove('*.vcxproj')
	os.remove('*.filters')
	os.remove('*.user')
	os.remove('*.vcxproj')
	os.rmdir('log_history')
end
 
--]]

