#pragma once

#ifdef OGL_PLATFORM_WINDOWS
	#ifdef OGL_BUILD_DLL
		#define OGL_API __declspec(dllexport)
	#else
		#define OGL_API __declspec(dllimport)
	#endif
#else
	#error Only Windows
#endif