#include "Win64Window.h"
#include "hf/Log.h"

hf::Win64Window::Win64Window(hf::Event::EventBus& eventBus, hf::WindowParameters& params)
	:hf::Window(eventBus)
{
	m_WindowData.Width = params.Width;
	m_WindowData.Height = params.Height;
	m_WindowData.Title = params.Title;
}

hf::Win64Window::~Win64Window()
{
	glfwDestroyWindow(m_Window);
	if (glfwInit())
	{
		glfwTerminate();
	}
}

bool hf::Win64Window::Init()
{
	if (!glfwInit())
	{
		//Failed to initialise the window
		HF_CORE_ERROR("Failed to Initialise window");
		return false;
	}

	m_Window = glfwCreateWindow((int)m_WindowData.Width, (int)m_WindowData.Height, m_WindowData.Title.c_str(), nullptr, nullptr);
	if (!m_Window)
	{
		HF_CORE_ERROR("Failed to Initialise window");
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(m_Window);
	SetVSync(true);
	return true;
}

void hf::Win64Window::Update()
{
	glfwPollEvents();
	glfwSwapBuffers(m_Window);
}

void hf::Win64Window::OnUpdate()
{
}

void hf::Win64Window::SetVSync(bool enabled)
{
	glfwSwapInterval(enabled);
}

bool hf::Win64Window::IsVSync() const
{
	return false;
}
