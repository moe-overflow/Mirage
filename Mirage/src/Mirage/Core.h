#pragma once

// macros for importing and exporting dll functions
#ifdef MIRAGE_PLATFORM_WINDOWS

	#ifdef MIRAGE_BUILD_DLL
		#define MIRAGE_API __declspec(dllexport)
	#else
		#define MIRAGE_API __declspec(dllimport)
	#endif
#else
	#error Mirage supports currently only windows!
#endif
