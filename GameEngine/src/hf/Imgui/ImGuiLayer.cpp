#include "ImGuiLayer.h"
#include <hf/Log.h>

hf::ImGui::ImGuiLayer::ImGuiLayer()
    :hf::Layer::Layer("ImGuiLayer")
{
}

hf::ImGui::ImGuiLayer::~ImGuiLayer()
{
}

void hf::ImGui::ImGuiLayer::OnAttach()
{
    HF_CORE_INFO("ImGui Layer Attached");

    //Initialize ImGui context here ???
}

void hf::ImGui::ImGuiLayer::OnDetach()
{
}

void hf::ImGui::ImGuiLayer::OnUpdate(float deltaTime)
{
}

void hf::ImGui::ImGuiLayer::OnEvent(hf::Event::Event& event)
{
}
