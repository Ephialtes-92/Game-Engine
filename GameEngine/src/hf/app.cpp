#include "app.h"
#include "Log.h"
#include "Events/EventDispatcher.h"
#include "Events/WindowEvent.h"

#ifdef HF_PLATFORM_WINDOWS
#include <Platform/Windows/Win64Window.h>
#endif // HF_PLATFORM_WINDOWS

namespace hf
{
    app::app() 
        : m_EventBus()
    {
#ifdef HF_PLATFORM_WINDOWS
        hf::WindowParameters windowParams;
        m_Window = std::make_unique<Win64Window>(m_EventBus, windowParams);
#endif
        m_EventBus.AddListener(this);

        //Maybe extract this to a separate function in the future
        m_Window->Init();
    }

    hf::app::~app()
	{
        //m_EventBus.Stop();
	}

	void app::Run()
	{
        //There should be a m_Running boolean to control this loop
        while (m_Running)
        {
            // Simulate OS events
            m_Window->Update();
            m_EventBus.DispatchPending();

        }
	}
    void app::OnEvent(Event::Event& event)
    {
        Event::EventDispatcher dispatcher(event);

        //Handle WindowCloseEvent
        dispatcher.Dispatch<Event::WindowCloseEvent>([this](Event::WindowCloseEvent& event) {
            // Game logic, rendering, etc.
            std::this_thread::sleep_for(std::chrono::milliseconds(500));

            HF_CORE_WARN("Window Closed 22");
            return true; 
            });


    }
}
