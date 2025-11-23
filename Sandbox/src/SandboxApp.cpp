#include <Hephaestus.h>

#include <hf/Imgui/ImGuiLayer.h>

//Ecaple Layer to be removed later
class Examplelayer : public hf::Layer::Layer
{
public:
    Examplelayer() : Layer("Example") {}

    void OnAttach() override
    {
        HF_CORE_INFO("Example Layer Attached");
    }

    void OnDetach() override
    {
        HF_CORE_INFO("Example Layer Detached");
    }

    void OnUpdate(float deltaTime) override
    {
        //HF_CORE_INFO("Example Layer Updated: {0}", deltaTime);
    }

    void OnEvent(hf::Event::Event& event) override
    {
        HF_CORE_INFO("Example Layer Event Received: {0}", event.GetName());
        event.m_Handled = true;
    }
};


class Sandbox : public hf::app
{
public :
	Sandbox() 
    {
        HF_CORE_INFO("Sandbox Application Created");
        PushLayer(new Examplelayer());  
        PushLayer(new hf::ImGui::ImGuiLayer());
    }

	~Sandbox() {}
};

hf::app* hf::CreateApplication()
{
	return new Sandbox();
}