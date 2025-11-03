#pragma once
#include "Event.h"

namespace hf::Event {

    class AppTickEvent : public Event
    {
    public:
        AppTickEvent() = default;
        EventType GetEventType() const override { return EventType::AppTick; }
        const char* GetName() const override { return "AppTickEvent"; }
        std::string ToString() const override { return "AppTickEvent"; }

        //Used by the dispatcher to compare event types
        static constexpr EventType StaticType = EventType::MouseButtonPressed;
    };

}