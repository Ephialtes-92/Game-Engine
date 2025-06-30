#pragma once

#ifdef HF_PLATFORM_WINDOWS

extern hf::app* hf::CreateApplication();


int main(int argc, char** argv)
{
	hf::app* application = hf::CreateApplication();
	application->Run();
	delete application;
}
#endif
