#include "hf/Window/Window.h"
#include <GLFW/glfw3.h>

namespace hf
{
	class Win64Window : public Window
	{
	public:
		Win64Window(Event::EventBus& eventBus, WindowParameters& params);

		bool Init() override;

		void PollEvents() override;
		void OnUpdate() override;

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		GLFWwindow* m_Window;
	};
}