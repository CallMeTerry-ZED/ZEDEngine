/*
 * © 2025 ZED Interactive. All Rights Reserved.
 */

#include "ZedCorePch.h"
#include "ZEDCore/Layer/LayerStack.h"

namespace ZED
{
    LayerStack::LayerStack()
    {

    }

    LayerStack::~LayerStack()
    {
        for (Layer *Layer : Layers)
        {
            delete Layer;
        }
    }

    void LayerStack::PushLayer(Layer *Layer)
    {
        Layers.emplace(Layers.begin() + LayerInsertIndex, Layer);
        LayerInsertIndex++;
        Layer->OnAttach();
    }

    void LayerStack::PushOverlay(Layer *Overlay)
    {
        Layers.emplace_back(Overlay);
        Overlay->OnAttach();
    }

    void LayerStack::PopLayer(Layer *Layer)
    {
        auto it = std::find(Layers.begin(), Layers.end(), Layer);
        if (it != Layers.end())
        {
            Layers.erase(it);
            LayerInsertIndex--;
            Layer->OnDetach();
        }
    }

    void LayerStack::PopOverlay(Layer *Overlay)
    {
        auto it = std::find(Layers.begin(), Layers.end(), Overlay);
        if (it != Layers.end())
        {
            Layers.erase(it);
            Overlay->OnDetach();
        }
    }
}
