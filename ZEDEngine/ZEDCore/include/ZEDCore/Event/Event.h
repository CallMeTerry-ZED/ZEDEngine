/*
 * © 2025 ZED Interactive. All Rights Reserved.
 */

#pragma once

#ifndef EVENT_H
#define EVENT_H

#include "ZEDCorePch.h"
#include "ZEDCore/Core.h"
#include "spdlog/fmt/bundled/format.h"

namespace ZED
{

    // Events are currently blocking which means if/when an event happens
    // it will always instantly get dispatched and must be handled right away
    // We should really be handling this with a buffer event that will be in an
    // Event bus then we process them during the event part of the update stage

    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased, KeyTyped,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication = ZEDBIT(0),
        EventCategoryInput = ZEDBIT(1),
        EventCategoryKeyboard = ZEDBIT(2),
        EventCategoryMouse = ZEDBIT(3),
        EventCategoryMouseButton = ZEDBIT(4)
    };

#define ZED_EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
                                   virtual EventType GetEventType() const override { return GetStaticType(); }\
                                   virtual const char* GetName() const override { return #type; }

#define ZED_EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

    class Event
    {
    public:
        bool Handled = false;

        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        inline bool IsInCategory(EventCategory category) { return GetCategoryFlags() & category; }
    };

    class EventDispatcher
    {
        template<typename T>
        using EventFunc = std::function<bool(T&)>;

    public:
        EventDispatcher(Event& event) : Event(event) {}

        template<typename T>
        bool Dispatch(EventFunc<T> func)
        {
            if (Event.GetEventType() == T::GetStaticType())
            {
                Event.Handled = func(*(T*)Event);
                return true;
            }
            return false;
        }

    private:
        Event& Event;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }
}

template <typename T>
struct fmt::formatter<T, std::enable_if_t<std::is_base_of_v<ZED::Event, T>, char>> : fmt::formatter<std::string>
{
    template <typename FormatContext>
    auto format(const T& e, FormatContext& ctx) const
    {
        return fmt::formatter<std::string>::format(e.ToString(), ctx);
    }
};

#endif //EVENT_H
