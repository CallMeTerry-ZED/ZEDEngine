/*
 * © 2025 ZED Interactive. All Rights Reserved.
 */

#include "ZEDCorePch.h"
#include "ZEDCore/Application/Application.h"

namespace ZED
{
#define BIND_EVENT_FUNC(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application* Application::Instance = nullptr;

    Application::Application()
    {
        ZED_CORE_ASSERT(!Instance, "Application already exists");
        Instance = this;
    }

    Application::~Application()
    {

    }

    void Application::PushLayer(Layer* layer)
    {
        LayerStack.PushLayer(layer);
    }

    void Application::PushOverlay(Layer* layer)
    {
        LayerStack.PushOverlay(layer);
    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(OnWindowClose));

        for (auto it = LayerStack.end(); it != LayerStack.begin(); )
        {
            (*--it)->OnEvent(e);
            if (e.Handled)
            {
                break;
            }
        }
    }

    void Application::Run()
    {
        while (Running)
        {
            for (Layer* layer : LayerStack)
            {
                layer->OnUpdate();
            }
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        Running = false;
        return true;
    }

}