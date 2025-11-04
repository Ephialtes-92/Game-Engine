#include "app.h"
#include "Log.h"
#include "Events/EventDispatcher.h"
#include "Events/WindowEvent.h"

namespace hf
{
    app::app() 
        : m_EventBus(), m_Window(m_EventBus)
    {
        m_EventBus.AddListener(this);
    }

    hf::app::~app()
	{
        m_EventBus.Stop();
	}

	void app::Run()
	{
        //There should be a m_Running boolean to control this loop
        while (m_Running)
        {
            // Simulate OS events
            m_Window.PollEvents();

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
