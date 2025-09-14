#*
# © 2025 ZED Interactive. All Rights Reserved.
#/

# Glob all source files recursively
file(GLOB_RECURSE SANDBOX_SOURCES
        "src/*.cpp"
        "src/*.c"
)

# Glob all header files recursively
file(GLOB_RECURSE SANDBOX_HEADERS
        "src/*.h"
        "src/*.hpp"
)

# Create Sandbox executable (only if sources exist)
if(SANDBOX_SOURCES)
    add_executable(Sandbox ${SANDBOX_SOURCES} ${SANDBOX_HEADERS})
else()
    # Create empty executable if no sources
    add_executable(Sandbox)
    message(STATUS "Sandbox: No source files found, creating empty executable")
endif()

# Link with ZEDCore
target_link_libraries(Sandbox PRIVATE
        ZEDCore
)

# Include directories
target_include_directories(Sandbox PRIVATE
        ${CMAKE_SOURCE_DIR}/ZEDEngine/ZEDCore/include
        ${CMAKE_SOURCE_DIR}/ZEDEngine/ZEDCore/src
)

# Compiler definitions
target_compile_definitions(Sandbox PRIVATE
        $<$<CONFIG:Debug>:ZED_DEBUG>
        $<$<CONFIG:Release>:ZED_RELEASE>
        $<$<CONFIG:RelWithDebInfo>:ZED_RELWITHDEBINFO>
        $<$<CONFIG:MinSizeRel>:ZED_MINSIZEREL>
        WIN32_LEAN_AND_MEAN
        ZED_PLATFORM_WIN32
        ZED_SANDBOX
)

# Set properties
set_target_properties(Sandbox PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)

# Set output directories
set_output_directories(Sandbox)
set_target_properties(Sandbox PROPERTIES FOLDER "GAMES")

message(STATUS "-----------------------------------------------------------")
message(STATUS "Copying steam_api.dll and steam_api64.dll to sandbox folder")
message(STATUS "------------------------------------------------------------")

# Paths to Steam DLLs
set(STEAM32_DLL "${CMAKE_SOURCE_DIR}/Thirdparty/steamworks-sdk-162/redistributable_bin/steam_api.dll")
set(STEAM64_DLL "${CMAKE_SOURCE_DIR}/Thirdparty/steamworks-sdk-162/redistributable_bin/win64/steam_api64.dll")

# Copy 32-bit DLL
add_custom_command(TARGET Sandbox POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${STEAM32_DLL}"
        $<TARGET_FILE_DIR:Sandbox>
        COMMAND_EXPAND_LISTS
)

# Copy 64-bit DLL
add_custom_command(TARGET Sandbox POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${STEAM64_DLL}"
        $<TARGET_FILE_DIR:Sandbox>
        COMMAND_EXPAND_LISTS
)

message(STATUS "--------------------------------------------------------------------")
message(STATUS "Copying steam_api.dll and steam_api64.dll to sandbox folder finished")
message(STATUS "--------------------------------------------------------------------")

message(STATUS "--------------------------------------------------------------------")
message(STATUS "Copying steam_appid.txt to sandbox folder")
message(STATUS "--------------------------------------------------------------------")

set(STEAMAPPID "${CMAKE_SOURCE_DIR}/Sandbox/steam_appid.txt")

# Copy 32-bit DLL
add_custom_command(TARGET Sandbox POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${STEAMAPPID}"
        $<TARGET_FILE_DIR:Sandbox>
        COMMAND_EXPAND_LISTS
)

message(STATUS "--------------------------------------------------------------------")
message(STATUS "Copying steam_appid.txt to sandbox folder finished")
message(STATUS "--------------------------------------------------------------------")