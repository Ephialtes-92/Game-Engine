#include "Window.h"
#include "hf/Events/WindowEvent.h"

//void hf::Window::Window::AddEventListener(hf::Event::IEventListener* listener)
//{
//    m_Listeners.push_back(listener);
//}
//
//void hf::Window::Window::RemoveEventListener(hf::Event::IEventListener* listener)
//{
//    m_Listeners.erase(std::remove(m_Listeners.begin(), m_Listeners.end(), listener), m_Listeners.end());
//}

hf::Window::Window::Window(hf::Event::EventBus& eventBus)
    : m_EventBus(eventBus)
{
}

void hf::Window::Window::PollEvents()
{
    //NotifyListeners(closeEvent);
    //Now instead of the window Notifying listeners on its own
    //we push the event to the EventBus
    //and let that handle the Event dispatching/handling
    auto closeEvent = std::make_unique<hf::Event::WindowCloseEvent>();
    m_EventBus.PushEvent(std::move(closeEvent));
}

//void hf::Window::Window::NotifyListeners(hf::Event::Event& event) const
//{
//    for (auto* listener : m_Listeners)
//    {
//        listener->OnEvent(event);
//        if (event.IsHandled())
//            break;
//    }
//}
