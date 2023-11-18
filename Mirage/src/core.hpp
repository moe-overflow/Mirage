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


/**
 * \brief macro for shifting bits => bit field. purpose: having the ability for making a kind of hierarchy
 *		  for event categories (A single event type can have more than one category)
 * \param x shifting positions
 */
#define BIT(x) (1 << (x))
