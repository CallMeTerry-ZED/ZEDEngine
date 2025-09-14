/*
 * © 2025 ZED Interactive. All Rights Reserved.
 */

#pragma once

#ifndef CORE_H
#define CORE_H

///////////////////// DEFINES FOR ENGINE AND OTHER APPS SO WE CAN REUSE THEM /////////////////////
#define ZEDBIT(x) (1 << x)

#define ZED_BIND_EVENT_FUNC(func) std::bind(&func, this, std::placeholders::_1)

#ifdef ZED_DEBUG
#define ZED_ENABLE_ASSERTS
#endif

#ifdef ZEDENGINE_ENABLE_ASSERTS
#define ZEDENGINE_ASSERT(x, ...) { if(!(x)) {ZED_ERROR("Assertion Failed: {0}, __VA_ARGS__"); __DebugBreak(); }}
#define ZED_CORE_ASSERT(x, ...) { if(!(x)) {ZED_CORE_ERROR("Assertion Failed: {0}, __VA_ARGS__"); __DebugBreak(); }}
#else
#define ZED_ASSERT(x, ...)
#define ZED_CORE_ASSERT(x, ...)
#endif
///////////////////// DEFINES FOR ENGINE AND OTHER APPS SO WE CAN REUSE THEM /////////////////////


#endif //CORE_H
