#include "Win64Window.h"
#include "hf/Log.h"

hf::Win64Window::Win64Window(hf::Event::EventBus& eventBus, hf::WindowParameters& params)
	:hf::Window(eventBus)
{
	SetWidth(params.Width);
	SetHeight(params.Height);
	SetTitle(params.Title);
}

//I want to be able to explicitly initialise this ???
bool hf::Win64Window::Init()
{
	if (!glfwInit())
	{
		//Failed to initialise the window
		HF_CORE_ERROR("Failed to Initialise window");
		SetIsInitialised(false);
		return false;
	}

	m_Window = glfwCreateWindow(GetWidth(), GetHeight(), GetTitle().c_str(), nullptr, nullptr);
	if (!m_Window)
	{
		//Failed to initialise the window
		HF_CORE_ERROR("Failed to Initialise window");
		SetIsInitialised(false);
		return false;
	}
	glfwMakeContextCurrent(m_Window);
	//This sets Vsync
	//glfwSwapInterval(1);
	SetIsInitialised(true);
	return true;
}

void hf::Win64Window::PollEvents()
{
	glfwPollEvents();
}

void hf::Win64Window::OnUpdate()
{
}

void hf::Win64Window::SetVSync(bool enabled)
{
}

bool hf::Win64Window::IsVSync() const
{
	return false;
}
