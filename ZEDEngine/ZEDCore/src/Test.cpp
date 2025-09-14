/*
 * © 2025 ZED Interactive. All Rights Reserved.
 */

#include "ZEDCorePch.h"
#include "ZEDCore/Test.h"
#include "steam/steam_api.h"
#include "imgui.h"
#include "glm/vec3.hpp"
#include "spdlog/version.h"
#include "SDL3/SDL.h"
#include "btBulletDynamicsCommon.h"
#include "vulkan/vulkan.h"
#include "ZEDCore/Log/Log.h"

namespace ZED
{
    void Test::TestSteam()
    {
        // Steam doesn't have a version constant
        // So to test it we can call its init and shutdown methods
        if (!SteamAPI_Init())
        {
            ZED_CORE_ERROR("SteamAPI: Failed to init Steam.");
        }

        // Get the current users Steam name
        const char *name = SteamFriends()->GetPersonaName();
        ZED_CORE_TRACE("SteamAPI: Current User's Name is {0}", name);

        SteamAPI_Shutdown();
    }

    void Test::TestBullet()
    {
        ZED_CORE_TRACE("Bullet version: {0}", BT_BULLET_VERSION);
    }


    void Test::TestSpdlog()
    {
        ZED_CORE_TRACE("Spdlog version: {0}", SPDLOG_VERSION);
    }

    void Test::TestImGui()
    {
        ZED_CORE_TRACE("ImGui version: {0}", IMGUI_VERSION);
    }

    void Test::TestSDL()
    {
        ZED_CORE_TRACE("SDL3 major and minor version: {0}.{1}", SDL_MAJOR_VERSION, SDL_MINOR_VERSION);
    }

    void Test::TestGLM()
    {
        // GLM doesn't have a version constant
        // So we test it with an actual math function
        glm::vec3 v1(1.0f, 2.0f, 3.0f);
        glm::vec3 v2(4.0f, 5.0f, 6.0f);
        glm::vec3 result = v1 + v2;
        ZED_CORE_TRACE("GLM vector math test: {0}, {1}, {2}", result.x, result.y, result.z);
    }

    void Test::TestVulkan()
    {
        ZED_CORE_TRACE("Vulkan API version: {0}", VK_API_VERSION_1_0);
    }
}