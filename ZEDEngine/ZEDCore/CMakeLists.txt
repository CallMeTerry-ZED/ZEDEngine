#*
# © 2025 ZED Interactive. All Rights Reserved.
#/

# Glob all source files recursively
file(GLOB_RECURSE ZEDCORE_SOURCES
        "src/*.cpp"
        "src/*.c"
)

# Glob all header files recursively
file(GLOB_RECURSE ZEDCORE_HEADERS
        "include/*.h"
        "include/*.hpp"
        "src/*.h"
        "src/*.hpp"
)

# Create ZEDCore library (only if sources exist)
if(ZEDCORE_SOURCES)
    add_library(ZEDCore STATIC ${ZEDCORE_SOURCES} ${ZEDCORE_HEADERS})
else()
    # Create empty library if no sources
    add_library(ZEDCore STATIC)
    message(STATUS "ZEDCore: No source files found, creating empty library")
endif()

target_precompile_headers(ZEDCore
        PRIVATE include/ZEDCorePch.h
)

# Include directories
target_include_directories(ZEDCore PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>

        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../Thirdparty/SDL-3.2.20/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Thirdparty/bullet3-3.25/src
        ${CMAKE_CURRENT_SOURCE_DIR}/../Thirdparty/spdlog-1.15.3/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../Thirdparty/glm-1.0.1
        ${CMAKE_CURRENT_SOURCE_DIR}/../Thirdparty/imgui-1.92.2b-docking
        ${CMAKE_CURRENT_SOURCE_DIR}/../Thirdparty/steamworks-sdk-162/public
)

# Link thirdparty libraries
target_link_libraries(ZEDCore PUBLIC
        ${SDL3_LIB}
        ${BULLET3_DYNAMICS}
        ${BULLET3_COLLISION}
        ${BULLET3_LINEAR}
        ${SPDLOG_LIB}
        ${GLM_LIB}
        ${IMGUI_LIB}
        ${STEAMWORKS_LIB}
        ${VULKAN_LIB}

)

# Compiler definitions
target_compile_definitions(ZEDCore PRIVATE
        $<$<CONFIG:Debug>:ZED_DEBUG>
        $<$<CONFIG:Release>:ZED_RELEASE>
        $<$<CONFIG:RelWithDebInfo>:ZED_RELWITHDEBINFO>
        $<$<CONFIG:MinSizeRel>:ZED_MINSIZEREL>
        ZED_ENGINE
)

target_compile_definitions(ZEDCore
        PUBLIC ZED_PLATFORM_WIN32
        PUBLIC GLFW_INCLUDE_NONE
)

# Set properties
set_target_properties(ZEDCore PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)

# Set output directories
set_output_directories(ZEDCore)
set_target_properties(ZEDCore PROPERTIES FOLDER "ENGINE")