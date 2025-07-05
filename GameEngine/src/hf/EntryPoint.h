#pragma once

#ifdef HF_PLATFORM_WINDOWS

#include "Log.h"

extern hf::app* hf::CreateApplication();


int main(int argc, char** argv)
{
	//Initialise
	hf::Log::Init();

	HF_CORE_WARN("Hello THERE");
	HF_CORE_ERROR("DOOOOOOOM");
	
	hf::app* application = hf::CreateApplication();
	application->Run();
	delete application;

	
}
#endif
