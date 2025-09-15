/*
 * © 2025 ZED Interactive. All Rights Reserved.
 */

#pragma once

#ifndef KEYEVENT_H
#define KEYEVENT_H

#include "ZEDCorePch.h"
#include "Event.h"

namespace ZED
{
    class KeyEvent : public Event
    {
    public:
        inline int GetKeyCode() const { return KeyCode; }

        ZED_EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
        KeyEvent(int KeyCode) : KeyCode(KeyCode) {}

        int KeyCode;
    };

    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int KeyCode, int RepeatCount) : KeyEvent(KeyCode), RepeatCount(RepeatCount) {}

        inline int GetRepeatCount() const { return RepeatCount; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << KeyCode << " (" << RepeatCount << " repeats)";
            return ss.str();
        }

        ZED_EVENT_CLASS_TYPE(KeyPressed)
    private:
        int RepeatCount;
    };

    class KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(int KeyCode) : KeyEvent(KeyCode) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << KeyCode;
            return ss.str();
        }

        ZED_EVENT_CLASS_TYPE(KeyReleased)
    };

    class KeyTypedEvent : public KeyEvent
    {
    public:
        KeyTypedEvent(int KeyCode) : KeyEvent(KeyCode) {}
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << KeyCode;
            return ss.str();
        }

        ZED_EVENT_CLASS_TYPE(KeyTyped)
    };
}

#endif //KEYEVENT_H
