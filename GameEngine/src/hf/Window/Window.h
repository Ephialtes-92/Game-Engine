#pragma once
//#include "hf/Events/IEventListener.h"
#include "hf/Events/EventBus.h"

#include <vector>

namespace hf::Window
{
    class Window 
    {
    public:
        Window(hf::Event::EventBus& eventBus);
        //void AddEventListener(hf::Event::IEventListener* listener);
        //void RemoveEventListener(hf::Event::IEventListener* listener);
        void PollEvents();

    private:
        //void NotifyListeners(hf::Event::Event& event) const;
        //std::vector<hf::Event::IEventListener*> m_Listeners;
        hf::Event::EventBus& m_EventBus;
    };
}

