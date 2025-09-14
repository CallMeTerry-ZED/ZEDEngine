/*
 * © 2025 ZED Interactive. All Rights Reserved.
 */

#pragma once

#ifndef APPLICATIONEVENT_H
#define APPLICATIONEVENT_H

#include "ZEDCorePch.h"
#include "Event.h"

namespace ZED
{
    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height) :
        Width(width), Height(height) {}

        inline  unsigned int GetWidth() { return Width; }
        inline  unsigned int GetHeight() { return Height; }

        std::string ToString() const override
        {
            std::stringstream ss;

            ss << "WindowResizeEvent(" << Width << ", " << Height << ")";
            return ss.str();
        }

        ZED_EVENT_CLASS_TYPE(WindowResize)
        ZED_EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:
        unsigned int Width, Height;
    };

    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() {}

        ZED_EVENT_CLASS_TYPE(WindowClose)
        ZED_EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class AppTickEvent : public Event
    {
    public:
        AppTickEvent() {}

        ZED_EVENT_CLASS_TYPE(AppTick)
        ZED_EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent() {}

        ZED_EVENT_CLASS_TYPE(AppUpdate)
        ZED_EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class AppRenderEvent : public Event
    {
    public:
        AppRenderEvent() {}

        ZED_EVENT_CLASS_TYPE(AppRender)
        ZED_EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
}

#endif //APPLICATIONEVENT_H
