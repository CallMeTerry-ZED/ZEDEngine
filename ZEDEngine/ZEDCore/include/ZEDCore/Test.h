/*
 * © 2025 ZED Interactive. All Rights Reserved.
 */

#pragma once

#ifndef TEST_H
#define TEST_H

#include "ZEDCorePch.h"

namespace ZED
{
    class Test
    {
    public:
        static void TestSteam();
        static void TestBullet();
        static void TestSpdlog();
        static void TestImGui();
        static void TestSDL();
        static void TestGLM();
        static void TestVulkan();
    };
}

#endif //TEST_H
