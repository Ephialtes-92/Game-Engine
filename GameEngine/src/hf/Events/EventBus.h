#pragma once
#include <thread>
#include <atomic>
#include <vector>
#include <memory>
#include "IEventListener.h"
#include "hf/Containers/ThreadSafeQueue.h"


namespace hf::Event {
    class EventBus {

    public: 
        void AddListener(IEventListener* listener);
        void RemoveListener(IEventListener* listener);
        void PushEvent(std::unique_ptr<Event> event);
        void PushBlockingEvent(std::unique_ptr<Event> event);
        void DispatchPending();
        void DispatchToListeners(Event& event);
        //void Stop();

    private:
        //void Run();
        //void DispatchEvent(Event& event);

        Containers::ThreadSafeQueue<std::unique_ptr<Event>> m_Queue;
        std::vector<IEventListener*> m_Listeners;
        std::mutex m_ListenerMutex;

        std::atomic<bool> m_Running;
        std::thread m_Worker;

    };
}