#pragma once
#include <hf/Layers/Layer.h>
#include "hf/Core.h"
#include <vector>
namespace hf::Layer
{
    class HF_API LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();
        void PushLayer(Layer* layer);
        //Overlays are always on top
        void PushOverlay(Layer* overlay);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* overlay);
        //void UpdateLayers(float deltaTime);s

        std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
        std::vector<Layer*>::iterator end() { return m_Layers.end(); }

    private:
        std::vector<Layer*> m_Layers;
        std::vector<Layer*>::iterator m_LayerInsert;
    };
} // namespace hf::Layer