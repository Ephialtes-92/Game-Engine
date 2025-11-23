#pragma once

#include <hf/Layers/Layer.h>

namespace hf::ImGui
{
	class HF_API ImGuiLayer : public hf::Layer::Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate(float deltaTime) override;
		void OnEvent(hf::Event::Event& event) override;

	};
}