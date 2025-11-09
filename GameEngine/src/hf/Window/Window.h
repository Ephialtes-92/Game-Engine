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
        virtual ~Window() = default;

        virtual bool Init() = 0;

        virtual void Update() = 0;
        virtual void OnUpdate() = 0;

        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

    private:
        hf::Event::EventBus& m_EventBus;
    };
}

