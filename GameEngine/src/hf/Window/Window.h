#pragma once
#include "hf/Events/EventBus.h"
#include "hf/Core.h"

namespace hf
{

    struct WindowParameters
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowParameters(const std::string title = "Hephaestus Engine",
            unsigned int w = 1280,
            unsigned int h = 720)
            :Title(title), Width(w), Height(h)
        {
        }

    };

    class HF_API Window
    {
    public:
        Window(hf::Event::EventBus& eventBus) : m_EventBus(eventBus) {}
        //virtual ~Window() {}

        virtual bool Init() = 0;

        virtual void PollEvents() = 0;
        virtual void OnUpdate() = 0;

        bool IsInitialised() const { return m_IsInitialised; }
        void SetIsInitialised(bool value) { m_IsInitialised = value; }

        unsigned int GetWidth() const { return m_Width; }
        unsigned int GetHeight() const { return m_Height; }
        std::string GetTitle() const { return m_Title; }

        void SetWidth(unsigned int w) { m_Width = w; }
        void SetHeight(unsigned int h) { m_Height = h; }
        void SetTitle(std::string& t) { m_Title = t; }

        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

    private:
        hf::Event::EventBus& m_EventBus;
        bool m_IsInitialised = false;
        unsigned int m_Width = 0;
        unsigned int m_Height = 0;
        std::string m_Title = "";
    };
}

