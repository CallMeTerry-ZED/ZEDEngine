/*
 * © 2025 ZED Interactive. All Rights Reserved.
 */

#pragma once

#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#ifdef ZED_PLATFORM_WIN32
extern ZED::Application* ZED::CreateApplication();

int main(int argc, char** argv)
{
    ZED::Log::Init();
    ZED_CORE_INFO("Core Logger Initialized!");
    ZED_CLIENT_INFO("Client Logger Initialized!");
    ZED_SERVER_INFO("Server Logger Initialized!");

    auto app = ZED::CreateApplication();
    app->Run();
    delete app;

    return 0;
}
#endif

#endif //ENTRYPOINT_H
