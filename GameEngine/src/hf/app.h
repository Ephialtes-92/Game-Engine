#pragma once

#include "Core.h"
#include "Events/IEventListener.h"
#include "Window/Window.h"

namespace hf
{
    class HF_API app : public Event::IEventListener
	{
	public:
		app();
		virtual ~app();

		void Run();


        void OnEvent(Event::Event& e) override;
    
    private:
        Window::Window m_Window;
	};

	//To be defined in client
	app* CreateApplication();


}

