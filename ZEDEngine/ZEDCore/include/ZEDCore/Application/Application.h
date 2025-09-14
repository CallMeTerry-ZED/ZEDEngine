/*
 * © 2025 ZED Interactive. All Rights Reserved.
 */

#pragma once

#ifndef APPLICATION_H
#define APPLICATION_H

#include "ZEDCorePch.h"
#include "ZedCore/Core.h"
#include "ZedCore/Layer/LayerStack.h"
#include "ZEDCore/Event/Event.h"
#include "ZEDCore/Event/ApplicationEvent.h"

namespace ZED
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
        void OnEvent(Event& e);
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline static Application& Get() { return *Instance; }

    private:
        bool OnWindowClose(WindowCloseEvent& e);

        bool Running = true;
        LayerStack LayerStack;
        static Application* Instance;
    };

    // CLIENT DEFINED
    Application* CreateApplication();
}

#endif //APPLICATION_H
