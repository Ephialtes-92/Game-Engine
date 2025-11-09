#include "hf/Window/Window.h"
#include <GLFW/glfw3.h>

namespace hf
{
	class HF_API Win64Window : public Window
	{
	public:
		Win64Window(Event::EventBus& eventBus, WindowParameters& params);
		virtual ~Win64Window();

		bool Init() override;

		void Update() override;

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		GLFWwindow* m_Window;

		struct WindowData 
		{
			unsigned int Width = 0;
			unsigned int Height = 0;
			std::string Title = "";
		};

	private:
		WindowData m_WindowData;

		//Window events
		virtual void OnClose();
	};
}