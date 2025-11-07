#pragma once
#include "Event.h"

namespace hf::Event {
    class MouseButtonPressedEvent : public Event
    {
    public:
        MouseButtonPressedEvent(int button)
            : m_Button(button) {
        }
        EventType GetEventType() const override { return EventType::MouseButtonPressed; }
        const char* GetName() const override { return "MouseButtonPressedEvent"; }
        std::string ToString() const override
        {
            return "MouseButtonPressedEvent: " + std::to_string(m_Button);
        }
        int GetButton() const { return m_Button; }

        //Used by the dispatcher to compare event types
        static constexpr EventType StaticType = EventType::MouseButtonPressed;

    private:
        int m_Button = 0;
    };
}