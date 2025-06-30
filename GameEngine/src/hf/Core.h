#pragma once

#ifdef HF_PLATFORM_WINDOWS
	#ifdef HF_BUILD_DLL
		#define HF_API __declspec(dllexport)
	#else
		#define HF_API __declspec(dllimport)
	#endif
#else
	#error We only support Windows
#endif