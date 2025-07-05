#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace hf
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		//TODO customize this properly
		spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] %v");

		s_CoreLogger = spdlog::stdout_color_mt("HF_Core");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("HF_Client");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

} //namespace hf


