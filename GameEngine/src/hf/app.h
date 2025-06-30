#pragma once

#include "Core.h"

namespace hf
{
	class HF_API app
	{
	public:
		app();
		virtual ~app();

		void Run();
	};

	//To be defined in client
	app* CreateApplication();
}

