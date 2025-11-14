#pragma once

#include "Core.h"
#include "Events/IEventListener.h"
#include "Window/Window.h"
#include "Events/EventBus.h"
#include "Layers/LayerStack.h"

namespace hf
{
    class HF_API app : public Event::IEventListener
	{
	public:
        app();
		virtual ~app();

		void Run();


        void OnEvent(Event::Event& e) override;

        void PushLayer(Layer::Layer* layer);
        void PushOverlay(Layer::Layer* overlay);
    
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;

        Layer::LayerStack m_LayerStack;
        Event::EventBus m_EventBus;
	};

	//To be defined in client
	app* CreateApplication();


}

