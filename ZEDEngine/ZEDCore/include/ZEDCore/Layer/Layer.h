/*
 * © 2025 ZED Interactive. All Rights Reserved.
 */

#pragma once

#ifndef LAYER_H
#define LAYER_H

#include "ZEDCorePch.h"
#include "ZEDCore/Core.h"
#include "ZEDCore/Event/Event.h"

namespace ZED
{
    class Layer
    {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnImGuiRender() {}
        virtual void OnEvent(Event& event) {}

        inline const std::string& GetName() const { return DebugName; }

    protected:
        std::string DebugName;
    };
}

#endif //LAYER_H
