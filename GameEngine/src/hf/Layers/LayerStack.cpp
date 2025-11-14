#include "LayerStack.h"

hf::Layer::LayerStack::LayerStack()
{
    m_LayerInsert = m_Layers.begin();
}

hf::Layer::LayerStack::~LayerStack()
{
    for (Layer* layer : m_Layers)
    {
        delete layer;
    }
}

void hf::Layer::LayerStack::PushLayer(Layer* layer)
{
    m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
    layer->OnAttach();
}

void hf::Layer::LayerStack::PushOverlay(Layer* overlay)
{
    m_Layers.emplace_back(overlay);
    overlay->OnAttach();
}

void hf::Layer::LayerStack::PopLayer(Layer* layer)
{
    auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
    if (it != m_Layers.end())
    {
        (*it)->OnDetach();
        m_Layers.erase(it);
        m_LayerInsert--;
    }
}

void hf::Layer::LayerStack::PopOverlay(Layer* overlay)
{
    auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
    if (it != m_Layers.end())
    {
        (*it)->OnDetach();
        m_Layers.erase(it);
    }
}
