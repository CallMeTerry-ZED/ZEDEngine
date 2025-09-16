/*
 * © 2025 ZED Interactive. All Rights Reserved.
 */

#include "ZEDCore.h"

class TestLayer : public ZED::Layer
{
public:
    TestLayer() : Layer("Test Layer")
    {
        ZED::Test::TestSteam();
        ZED::Test::TestBullet();
        ZED::Test::TestGLM();
        ZED::Test::TestImGui();
        ZED::Test::TestSDL();
        ZED::Test::TestSpdlog();
        ZED::Test::TestVulkan();
    }

    void OnUpdate() override
    {

    }

    void OnEvent(ZED::Event& event) override
    {

    }

    ~TestLayer()
    {

    }
};

// Sandbox app skeleton inherits from
// ZED Engine's Application class
class Sandbox : public ZED::Application
{
public:
    Sandbox()
    {
        PushLayer(new TestLayer());
    }

    ~Sandbox()
    {

    }
};

// Return a pointer of our sandbox app skel to ZED Engine
// So it can create it using our entrypoint
ZED::Application* ZED::CreateApplication()
{
    return new Sandbox();
}