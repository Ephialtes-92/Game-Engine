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
        "%{prj.location}/ThirdParty/glfw/include"
    }

    links
    {
        "glfw",
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
            "HF_BUILD_DLL"
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
        buildoptions "/MDd"

    filter "configurations:Retail"
        defines "HF_RETAIL"
        optimize "On"
        buildoptions "/MDd"

    --filter { "system:windows", "configurations:Release"}
        --buildoptions "/MT"
    
include "GameEngine/ThirdParty/glfw"

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
        buildoptions "/MDd"

    filter "configurations:Retail"
        defines "HF_RETAIL"
        optimize "On"
        buildoptions "/MDd"

