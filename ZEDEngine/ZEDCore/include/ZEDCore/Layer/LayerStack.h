/*
 * © 2025 ZED Interactive. All Rights Reserved.
 */

#pragma once

#ifndef LAYERSTACK_H
#define LAYERSTACK_H

#include "ZEDCorePch.h"
#include "ZEDCore/Core.h"
#include "ZEDCore/Layer/Layer.h"

namespace ZED
{
    class LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer* Layer);
        void PushOverlay(Layer* Overlay);
        void PopLayer(Layer* Layer);
        void PopOverlay(Layer* Overlay);

        std::vector<Layer*>::iterator begin() { return Layers.begin(); }
        std::vector<Layer*>::iterator end() { return Layers.end(); }

    private:
        std::vector<Layer*> Layers;
        unsigned int LayerInsertIndex = 0;
    };
}

#endif //LAYERSTACK_H
