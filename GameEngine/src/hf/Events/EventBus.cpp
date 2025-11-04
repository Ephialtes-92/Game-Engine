#include "EventBus.h"

hf::Event::EventBus::~EventBus()
{
    Stop();
}

void hf::Event::EventBus::AddListener(IEventListener* listener)
{
    std::lock_guard<std::mutex> lock(m_ListenerMutex);
    m_Listeners.push_back(listener);
}

void hf::Event::EventBus::RemoveListener(IEventListener* listener)
{
    std::lock_guard<std::mutex> lock(m_ListenerMutex);
    m_Listeners.erase(std::remove(m_Listeners.begin(), m_Listeners.end(), listener), m_Listeners.end());
}

void hf::Event::EventBus::PushEvent(std::unique_ptr<Event> event)
{
    //The queue is lock free, so we can just push the event
    m_Queue.Push(std::move(event));
}

void hf::Event::EventBus::Stop()
{
    if (!m_Running) return;
    m_Running = false;
    m_Queue.Stop();
    if (m_Worker.joinable())
        m_Worker.join();
}

//This function is run on the worker thread
//For now the worker thread handles the events one by one
void hf::Event::EventBus::Run()
{
    while (m_Running)
    {
        auto eventOpt = m_Queue.PopBlocking();
        if (!eventOpt.has_value())
            break; // Queue stopped and empty
        std::unique_ptr<Event> event = std::move(eventOpt.value());
        DispatchEvent(*event);
    }
}

void hf::Event::EventBus::DispatchEvent(Event& event)
{
    std::vector<IEventListener*> listenersCopy;
    {
        std::lock_guard<std::mutex> lock(m_ListenerMutex);
        listenersCopy = m_Listeners; // copy to avoid lock contention during dispatch
    }

    for (auto* listener : listenersCopy)
    {
        listener->OnEvent(event);
        if (event.IsHandled())
            break;
    }
}
