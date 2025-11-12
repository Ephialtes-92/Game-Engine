#include "Win64Window.h"
#include "hf/Log.h"

//Events
#include "hf/Events/WindowEvent.h"

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

	//Store *this inside the GLFW window
	glfwSetWindowUserPointer(m_Window, this);

	//This lambda needs to be a valid C function pointer
	//so it cannot capture anything
	glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
	{
		//Retrieve the Window instance that owns this GLFW window
		auto* self = static_cast<Win64Window*>(glfwGetWindowUserPointer(window));
		if (self)
		{
			self->OnClose();
		}
	});





	return true;
}

void hf::Win64Window::Update()
{
	glfwPollEvents();
	glfwSwapBuffers(m_Window);
}

void hf::Win64Window::SetVSync(bool enabled)
{
	glfwSwapInterval(enabled);
}

bool hf::Win64Window::IsVSync() const
{
	return false;
}

void hf::Win64Window::OnClose()
{
	m_EventBus.PushBlockingEvent(std::make_unique<hf::Event::WindowCloseEvent>());
}
