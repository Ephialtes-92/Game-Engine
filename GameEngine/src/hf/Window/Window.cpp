#include "Window.h"
#include "hf/Events/WindowEvent.h"

//hf::Window(hf::Event::EventBus& eventBus)
//    : m_EventBus(eventBus)
//{
//}
//s
//void hf::Window::PollEvents()
//{
//    //NotifyListeners(closeEvent);
//    //Now instead of the window Notifying listeners on its own
//    //we push the event to the EventBus
//    //and let that handle the Event dispatching/handling
//    auto closeEvent = std::make_unique<hf::Event::WindowCloseEvent>();
//    m_EventBus.PushEvent(std::move(closeEvent));
//}
