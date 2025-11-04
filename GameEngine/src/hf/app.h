#pragma once

#include "Core.h"
#include "Events/IEventListener.h"
#include "Window/Window.h"
#include "Events/EventBus.h"

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
        bool m_Running = true;
        Event::EventBus m_EventBus;
	};

	//To be defined in client
	app* CreateApplication();


}

