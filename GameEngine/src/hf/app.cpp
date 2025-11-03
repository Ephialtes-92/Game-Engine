#include "app.h"
#include "Log.h"
#include "Events/EventDispatcher.h"
#include "Events/WindowEvent.h"

namespace hf
{
	hf::app::app()
	{
        m_Window.AddEventListener(this);
	}

	hf::app::~app()
	{
        m_Window.RemoveEventListener(this);
	}
	void app::Run()
	{
        //There should be a m_Running boolean to control this loop
        while (true)
        {
            m_Window.PollEvents();
        }
	}
    void app::OnEvent(Event::Event& event)
    {
        Event::EventDispatcher dispatcher(event);

        //Handle WindowCloseEvent
        dispatcher.Dispatch<Event::WindowCloseEvent>([this](Event::WindowCloseEvent& event) {
            HF_CORE_WARN("Window Closed 22");
            return true; 
            });


    }
}
