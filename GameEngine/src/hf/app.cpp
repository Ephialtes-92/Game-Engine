#include "app.h"
#include "Log.h"

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
        if (event.GetEventType() == hf::Event::EventType::WindowClose)
        {
            HF_CORE_WARN("Window Closed");
            event.m_Handled = true;
        }

    }
}
