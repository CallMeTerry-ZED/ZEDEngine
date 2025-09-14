#*
# © 2025 ZED Interactive. All Rights Reserved.
#/

cmake_minimum_required(VERSION 3.16)
project(ZEDEngine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable solution folders in Visual Studio
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Set output directories (relative paths)
set(OUTPUT_DIR "../Bin")
set(INTERMEDIATE_DIR "../Bin-Int")

# Set per-target output directories
macro(set_output_directories target_name)
    set_target_properties(${target_name} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}/${target_name}/Win32/x64/$<CONFIG>
            LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}/${target_name}/Win32/x64/$<CONFIG>
            ARCHIVE_OUTPUT_DIRECTORY ${INTERMEDIATE_DIR}/${target_name}/Win32/x64/$<CONFIG>

            # Per-configuration directories
            RUNTIME_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DIR}/${target_name}/Win32/x64/Debug
            RUNTIME_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_DIR}/${target_name}/Win32/x64/Release
            RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${OUTPUT_DIR}/${target_name}/Win32/x64/RelWithDebInfo
            RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${OUTPUT_DIR}/${target_name}/Win32/x64/MinSizeRel

            LIBRARY_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DIR}/${target_name}/Win32/x64/Debug
            LIBRARY_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_DIR}/${target_name}/Win32/x64/Release
            LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO ${OUTPUT_DIR}/${target_name}/Win32/x64/RelWithDebInfo
            LIBRARY_OUTPUT_DIRECTORY_MINSIZEREL ${OUTPUT_DIR}/${target_name}/Win32/x64/MinSizeRel

            ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${INTERMEDIATE_DIR}/${target_name}/Win32/x64/Debug
            ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${INTERMEDIATE_DIR}/${target_name}/Win32/x64/Release
            ARCHIVE_OUTPUT_DIRECTORY_RELWITHDEBINFO ${INTERMEDIATE_DIR}/${target_name}/Win32/x64/RelWithDebInfo
            ARCHIVE_OUTPUT_DIRECTORY_MINSIZEREL ${INTERMEDIATE_DIR}/${target_name}/Win32/x64/MinSizeRel
    )
endmacro()

message(STATUS "-----------------------------------------------------")
message(STATUS "Configuring: ZEDEngine Project")
message(STATUS "-----------------------------------------------------")

message(STATUS "-----------------------------------------------------")
message(STATUS "Configuring: ZEDEngine Thirdparty Libs")
message(STATUS "-----------------------------------------------------")

# Configure Bullet3
message(STATUS "-----------------------------------------------------")
message(STATUS "Configuring: bullet3 3.25")
message(STATUS "-----------------------------------------------------")

# Disable unnecessary Bullet3 components
set(BUILD_BULLET2_DEMOS OFF CACHE BOOL "Build Bullet2 demos" FORCE)
set(BUILD_BULLET3 OFF CACHE BOOL "Build Bullet3 demos" FORCE)
set(BUILD_EXTRAS OFF CACHE BOOL "Build extra Bullet examples" FORCE)
set(BUILD_UNIT_TESTS OFF CACHE BOOL "Build Bullet unit tests" FORCE)
set(BUILD_CPU_DEMOS OFF CACHE BOOL "Build CPU demos" FORCE)
set(BUILD_OPENGL3_DEMOS OFF CACHE BOOL "Build OpenGL3 demos" FORCE)
set(BUILD_EGL OFF CACHE BOOL "Build EGL" FORCE)
set(USE_MSVC_RUNTIME_LIBRARY_DLL OFF CACHE BOOL "Use MSVC runtime library DLL" FORCE)

# Add Bullet3 subdirectory
add_subdirectory("Thirdparty/bullet3-3.25" ${CMAKE_BINARY_DIR}/bullet3)

# Set Bullet3 library variables for easy reference
set(BULLET3_DYNAMICS BulletDynamics)
set(BULLET3_COLLISION BulletCollision)
set(BULLET3_LINEAR LinearMath)
set(BULLET3_SOFTBODY BulletSoftBody)
set(BULLET3_INVERSE BulletInverseDynamics)
set(BULLET3_COMMON Bullet3Common)

# Set Bullet3 projects to THIRDPARTY solution folder
set_output_directories(${BULLET3_DYNAMICS})
set_target_properties(${BULLET3_DYNAMICS} PROPERTIES FOLDER "THIRDPARTY")

set_output_directories(${BULLET3_COLLISION})
set_target_properties(${BULLET3_COLLISION} PROPERTIES FOLDER "THIRDPARTY")

set_output_directories(${BULLET3_LINEAR})
set_target_properties(${BULLET3_LINEAR} PROPERTIES FOLDER "THIRDPARTY")

# Also organize other Bullet targets if they exist
if(TARGET ${BULLET3_SOFTBODY})
    set_output_directories(${BULLET3_SOFTBODY})
    set_target_properties(${BULLET3_SOFTBODY} PROPERTIES FOLDER "THIRDPARTY")
endif()
if(TARGET ${BULLET3_INVERSE})
    set_output_directories(${BULLET3_INVERSE})
    set_target_properties(${BULLET3_INVERSE} PROPERTIES FOLDER "THIRDPARTY")
endif()
if(TARGET ${BULLET3_COMMON})
    set_output_directories(${BULLET3_COMMON})
    set_target_properties(${BULLET3_COMMON} PROPERTIES FOLDER "THIRDPARTY")
endif()

# Configure SDL3
message(STATUS "-----------------------------------------------------")
message(STATUS "Configuring: SDL3 3.2.20")
message(STATUS "-----------------------------------------------------")

set(SDL_SHARED OFF CACHE BOOL "Build SDL3 as static library" FORCE)
set(SDL_STATIC ON CACHE BOOL "Build SDL3 as static library" FORCE)
set(SDL_TEST OFF CACHE BOOL "Don't build SDL3 tests" FORCE)
set(SDL_INSTALL OFF CACHE BOOL "Don't generate install target" FORCE)

# Add SDL3 subdirectory
add_subdirectory("Thirdparty/SDL-3.2.20")

# Set SDL3_LIB variable for consistency
set(SDL3_LIB SDL3-static)

# Set SDL3 output directories and solution folder if target exists
if(TARGET SDL3-static)
    set_output_directories(SDL3-static)
    set_target_properties(SDL3-static PROPERTIES FOLDER "THIRDPARTY")
endif()

# Configure spdlog
message(STATUS "-----------------------------------------------------")
message(STATUS "Configuring: spdlog 1.15.3")
message(STATUS "-----------------------------------------------------")

set(SPDLOG_BUILD_EXAMPLE OFF CACHE BOOL "Don't build spdlog examples" FORCE)
set(SPDLOG_BUILD_EXAMPLE_HO OFF CACHE BOOL "Don't build spdlog header-only examples" FORCE)
set(SPDLOG_BUILD_TESTS OFF CACHE BOOL "Don't build spdlog tests" FORCE)
set(SPDLOG_BUILD_TESTS_HO OFF CACHE BOOL "Don't build spdlog header-only tests" FORCE)
set(SPDLOG_BUILD_BENCH OFF CACHE BOOL "Don't build spdlog benchmarks" FORCE)

# Add spdlog subdirectory
add_subdirectory("Thirdparty/spdlog-1.15.3")

# Set SPDLOG_LIB variable for consistency
set(SPDLOG_LIB spdlog)

# Set spdlog output directories and solution folder if target exists
if(TARGET spdlog)
    set_output_directories(spdlog)
    set_target_properties(spdlog PROPERTIES FOLDER "THIRDPARTY")
endif()

# Configure glm
message(STATUS "-----------------------------------------------------")
message(STATUS "Configuring: glm-1.0.1")
message(STATUS "-----------------------------------------------------")

set(GLM_BUILD_TESTS OFF CACHE BOOL "Don't build GLM tests" FORCE)
set(GLM_BUILD_INSTALL OFF CACHE BOOL "Don't generate install target" FORCE)
set(GLM_BUILD_LIBRARY OFF CACHE BOOL "Use header-only GLM" FORCE)

# Add GLM subdirectory
add_subdirectory("Thirdparty/glm-1.0.1")

# Set GLM_LIB variable for consistency
set(GLM_LIB glm)

# Set glm output directories and solution folder
set_output_directories(glm)
set_target_properties(glm PROPERTIES FOLDER "THIRDPARTY")

# Configure imgui
message(STATUS "-----------------------------------------------------")
message(STATUS "Configuring: imgui-1.92.2b-docking")
message(STATUS "-----------------------------------------------------")

# Add ImGui subdirectory
add_subdirectory("Thirdparty/imgui-1.92.2b-docking")

# Set IMGUI_LIB variable for consistency
set(IMGUI_LIB imgui)

# Set ImGui output directories and solution folder
set_output_directories(imgui)
set_target_properties(imgui PROPERTIES FOLDER "THIRDPARTY")

# Configure Steamworks
message(STATUS "-----------------------------------------------------")
message(STATUS "Configuring: steamworks-sdk-162")
message(STATUS "-----------------------------------------------------")

# Add Steamworks subdirectory
add_subdirectory("Thirdparty/steamworks-sdk-162")

# Set STEAMWORKS_LIB variable for consistency
set(STEAMWORKS_LIB steamworks)

# Set Steamworks output directories and solution folder
set_output_directories(steamworks)
set_target_properties(steamworks PROPERTIES FOLDER "THIRDPARTY")

# Configure Vulkan
message(STATUS "-----------------------------------------------------")
message(STATUS "Configuring: Vulkan SDK")
message(STATUS "-----------------------------------------------------")

# Find Vulkan package
find_package(Vulkan REQUIRED)

# Set VULKAN_LIB variable for consistency
set(VULKAN_LIB Vulkan::Vulkan)

# Set Vulkan output directories and solution folder if target exists
if(TARGET Vulkan::Vulkan)
    set_target_properties(Vulkan::Vulkan PROPERTIES FOLDER "THIRDPARTY")
endif()

message(STATUS "-----------------------------------------------------")
message(STATUS "ZEDEngine Thirdparty Libs Configuration Complete")
message(STATUS "-----------------------------------------------------")

message(STATUS "-----------------------------------------------------")
message(STATUS "Configuring: ZED ENGINE AND MODULES NOW")
message(STATUS "-----------------------------------------------------")

message(STATUS "-----------------------------------------------------")
message(STATUS "Configuring: ZED ENGINE: ZEDCore (LIB)")
message(STATUS "-----------------------------------------------------")

# Add ZedCore project
add_subdirectory(ZEDEngine/ZEDCore)

message(STATUS "-----------------------------------------------------")
message(STATUS "ZED ENGINE AND MODULES Configuration Complete")
message(STATUS "-----------------------------------------------------")

message(STATUS "-----------------------------------------------------")
message(STATUS "Configuring: Sandbox (Console App)")
message(STATUS "-----------------------------------------------------")

# Add Sandbox project
add_subdirectory(Sandbox)

message(STATUS "-----------------------------------------------------")
message(STATUS "ZEDEngine Configuration Complete")
message(STATUS "-----------------------------------------------------")