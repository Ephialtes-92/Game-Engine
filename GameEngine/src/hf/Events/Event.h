#pragma once
#include <string>

namespace hf::Event {
        enum class EventType
        {
            None = 0,
            WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,GLFWError,
            AppTick, AppUpdate, AppRender,
            KeyPressed, KeyReleased, KeyTyped,
            MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
        };

        class Event
        {
        public:
            //virtual ~Event() = default;
            virtual EventType GetEventType() const = 0;
            virtual const char* GetName() const = 0;
            virtual std::string ToString() const { return "Base Event"; }
            bool IsHandled() const { return m_Handled; }

            //Used by the dispatcher to compare event types
            static constexpr EventType StaticType = EventType::None;

            bool m_Handled = false;

        };
}