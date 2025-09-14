#*
# © 2025 ZED Interactive. All Rights Reserved.
#/

# ImGui library with backends included
add_library(imgui STATIC
        # Core ImGui files
        imgui.cpp
        imgui_demo.cpp
        imgui_draw.cpp
        imgui_tables.cpp
        imgui_widgets.cpp
        misc/cpp/imgui_stdlib.cpp

        # Backends for SDL3 + Vulkan + Win32
        backends/imgui_impl_sdl3.cpp
        backends/imgui_impl_vulkan.cpp
        backends/imgui_impl_win32.cpp
)

# Include directories
target_include_directories(imgui PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/Thirdparty/SDL-3.2.20/include
        ${CMAKE_SOURCE_DIR}/Thirdparty/SDL-3.2.20/src/video/khronos
)

# Compiler definitions
target_compile_definitions(imgui PRIVATE
        $<$<CONFIG:Debug>:IMGUI_DEBUG>
)

# Set properties
set_target_properties(imgui PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)

# Create interface target
add_library(imgui::imgui ALIAS imgui)