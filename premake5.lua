
-- latest premake5 is requered!  Not (alpha 12) !
-- https://github.com/premake/premake-core

-- 'premake5 vs2017' run this to generate VS2017 solution. 

workspace "fmt_extension"
	configurations { "Debug", "Release" }
	platforms {  "x64", "x32" }

	location ("./" .. (_ACTION or ""))
	language "C++"
	cppdialect "C++17"
	warnings "Extra"
	flags {  } 
	defines { }
	
	includedirs {  "../", "./include", "../include" }

	vpaths {
	   ["Headers/*"] = { "**.h", "**.hxx", "**.hpp" },
	   ["Source Files/*"] = { "**.cpp", "**.cc" },
	   ["Main"] = { "main.cpp" },  
	   ["Docs"] = "**.txt"
	}
	
	configuration "Debug"
		defines { "DEBUG" }
		symbols "On"
		
	configuration "Release"
		defines { "NDEBUG" }
		optimize "On"	
		optimize "Full"
		
	configuration "vs*"
		defines { "_CRT_SECURE_NO_WARNINGS" }
		flags { "MultiProcessorCompile"  } 
		cppdialect "C++latest"
		buildoptions {  }
		
	project "fmt_extension"
		kind "ConsoleApp"

		files { 
			"./**.h",
			"./**.hh",
			"./**.hpp",
			"./**.inl",

			"./**.c",
			"./**.cc",
			"./**.cpp",
		}
		
		removefiles  {
			"./build*/**.*",
			"./__*/**.*",
			"./#*/**.*"
		}

