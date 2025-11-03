#include "Window.h"
#include "hf/Events/WindowEvent.h"

void hf::Window::Window::AddEventListener(hf::Event::IEventListener* listener)
{
    m_Listeners.push_back(listener);
}

void hf::Window::Window::RemoveEventListener(hf::Event::IEventListener* listener)
{
    m_Listeners.erase(std::remove(m_Listeners.begin(), m_Listeners.end(), listener), m_Listeners.end());
}

void hf::Window::Window::PollEvents()
{
    //Example of polling a window close event
    hf::Event::WindowCloseEvent closeEvent;
    NotifyListeners(closeEvent);
}

void hf::Window::Window::NotifyListeners(hf::Event::Event& event) const
{
    for (auto* listener : m_Listeners)
    {
        listener->OnEvent(event);
        if (event.IsHandled())
            break;
    }
}
