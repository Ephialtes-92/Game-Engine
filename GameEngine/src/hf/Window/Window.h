#pragma once
#include "hf/Events/IEventListener.h"

#include <vector>

namespace hf::Window
{
    class Window 
    {
    public:
        void AddEventListener(hf::Event::IEventListener* listener);
        void RemoveEventListener(hf::Event::IEventListener* listener);
        void PollEvents();

    private:
        void NotifyListeners(hf::Event::Event& event) const;
        std::vector<hf::Event::IEventListener*> m_Listeners;
    };
}

