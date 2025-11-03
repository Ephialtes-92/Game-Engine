#pragma once
#include "Event.h"
namespace hf::Event {
    class IEventListener
    {
    public:
        virtual ~IEventListener() = default;
        virtual void OnEvent(class Event& event) = 0;
    };
}