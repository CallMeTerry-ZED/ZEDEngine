/*
 * © 2025 ZED Interactive. All Rights Reserved.
 */

#include "ZEDCore.h"

class TestLayer : public ZED::Layer
{
public:
    TestLayer() : Layer("Test Layer")
    {

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