#pragma once
#include "Event.h"

namespace hf::Event {

    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() = default;
        EventType GetEventType() const override { return EventType::WindowClose; }
        const char* GetName() const override { return "WindowCloseEvent"; }
        std::string ToString() const override { return "WindowCloseEvent"; }

        //Used by the dispatcher to compare event types
        static constexpr EventType StaticType = EventType::WindowClose;
    };

    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(int width, int height)
            : m_Width(width), m_Height(height) {
        }
        EventType GetEventType() const override { return EventType::WindowResize; }
        const char* GetName() const override { return "WindowResizeEvent"; }
        std::string ToString() const override
        {
            return "WindowResizeEvent: " + std::to_string(m_Width) + ", " + std::to_string(m_Height);
        }
        int GetWidth() const { return m_Width; }
        int GetHeight() const { return m_Height; }

        //Used by the dispatcher to compare event types
        static constexpr EventType StaticType = EventType::WindowResize;

    private:
        int m_Width = 0;
        int m_Height = 0;
    };

    class GLFWErrorEvent : public Event
    {
    public:
        GLFWErrorEvent(int errorCode, const std::string& description)
            : m_ErrorCode(errorCode), m_Description(description) {
        }
        EventType GetEventType() const override { return EventType::GLFWError; }
        const char* GetName() const override { return "GLFWError"; }
        std::string ToString() const override
        {
            return "GLFWError: " + std::to_string(m_ErrorCode) + ", " + m_Description;
        }


    private:
        int m_ErrorCode;
        std::string m_Description;
    };
}