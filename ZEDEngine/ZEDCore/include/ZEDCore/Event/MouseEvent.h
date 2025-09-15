/*
 * © 2025 ZED Interactive. All Rights Reserved.
 */

#pragma once

#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include "ZEDCorePch.h"
#include "Event.h"

namespace ZED
{
    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(float x, float y) : MouseX(x), MouseY(y) {}

        inline float GetX() const { return MouseX; }
        inline float GetY() const { return MouseY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << MouseX << ", " << MouseY;
            return ss.str();
        }

        ZED_EVENT_CLASS_TYPE(MouseMoved)
        ZED_EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float MouseX, MouseY;
    };

    class MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(float xOffSet, float yOffSet) : XOffset(xOffSet), YOffset(yOffSet) {}

        inline float GetXOffset() const { return XOffset; }
        inline float GetYOffset() const { return YOffset; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrollEvent: " << GetXOffset() << ", " << GetYOffset();
            return ss.str();
        }

        ZED_EVENT_CLASS_TYPE(MouseScrolled)
        ZED_EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float XOffset, YOffset;
    };

    class MouseButtonEvent : public Event
    {
    public:
        inline int GetMouseButton() const { return MButton; }

        ZED_EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    protected:
        MouseButtonEvent(int button) : MButton(button) {}

        int MButton;
    };

    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << MButton;
            return ss.str();
        }

        ZED_EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << MButton;
            return ss.str();
        }

        ZED_EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}

#endif //MOUSEEVENT_H
