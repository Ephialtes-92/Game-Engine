#pragma once

#include "Core.h"
#include "memory.h"
#include "spdlog/spdlog.h"

namespace hf
{
	class HF_API Log
	{
	public:

		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }


	private:

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};



//Core Log macros
#define HF_CORE_TRACE(...)   ::hf::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HF_CORE_INFO(...)    ::hf::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HF_CORE_WARN(...)    ::hf::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HF_CORE_ERROR(...)   ::hf::Log::GetCoreLogger()->error(__VA_ARGS__)
//#define HF_CORE_FATAL(...)   ::hf::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log macros
#define HF_TRACE(...)   ::hf::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HF_INFO(...)    ::hf::Log::GetClientLogger()->info(__VA_ARGS__)
#define HF_WARN(...)    ::hf::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HF_ERROR(...)   ::hf::Log::GetClientLogger()->error(__VA_ARGS__)
//#define HF_FATAL(...)   ::hf::Log::GetClientLogger()->fatal(__VA_ARGS__)




}//namespace hf

