#pragma once
#include "hf/Core.h"
#include <string>
#include "hf/Events/Event.h"

namespace hf::Layer
{
    class HF_API Layer
    {
    public:
        Layer(const std::string& name = "Layer")
            : m_DebugName(name)
        {
        }
        virtual ~Layer() = default;
        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate(float deltaTime) {}
        virtual void OnEvent(hf::Event::Event& event) {}
        inline const std::string& GetName() const { return m_DebugName; };

    private:
        std::string m_DebugName;
    };
} // namespace hf::Layer