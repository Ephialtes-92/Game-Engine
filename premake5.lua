workspace "Hephaestus"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Retail"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GameEngine"
    location "GameEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.location}/src/**.h",
        "%{prj.location}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.location}/src",
        "%{prj.location}/ThirdParty/spdlog/include",
        "%{prj.location}/ThirdParty/glfw/include",
        "%{prj.location}/ThirdParty/glad/include"
    }

    links
    {
        "glfw",
        "glad",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions { "/utf-8" }

        defines
        {
            "HF_PLATFORM_WINDOWS",
            "HF_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "HF_DEBUG"
        symbols "On"
        buildoptions "/MDd"

    filter "configurations:Release"
        defines "HF_RELEASE"
        symbols "On"
        optimize "On"
        buildoptions "/MT"

    filter "configurations:Retail"
        defines "HF_RETAIL"
        optimize "On"
        buildoptions "/MT"
    
include "GameEngine/ThirdParty/glfw"
include "GameEngine/ThirdParty/glad"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "GameEngine/ThirdParty/spdlog/include",
        "GameEngine/src"
    }

    links
    {
        "GameEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions { "/utf-8" }

        defines
        {
            "HF_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "HF_DEBUG"
        symbols "On"
        buildoptions "/MDd"

    filter "configurations:Release"
        defines "HF_RELEASE"
        symbols "On"
        optimize "On"
        buildoptions "/MT"

    filter "configurations:Retail"
        defines "HF_RETAIL"
        optimize "On"
        buildoptions "/MT"

