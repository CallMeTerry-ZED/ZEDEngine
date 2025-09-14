#*
# © 2025 ZED Interactive. All Rights Reserved.
#/

# Steamworks SDK - Header-only library with pre-compiled libs
add_library(steamworks INTERFACE)

# Include directories
target_include_directories(steamworks INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/public
)

# Compiler definitions
target_compile_definitions(steamworks INTERFACE
        $<$<CONFIG:Debug>:STEAM_DEBUG>
)

# Platform-specific linking
if(WIN32)
    target_link_libraries(steamworks INTERFACE
            ${CMAKE_CURRENT_SOURCE_DIR}/redistributable_bin/win64/steam_api64.lib
    )
elseif(APPLE)
    target_link_libraries(steamworks INTERFACE
            ${CMAKE_CURRENT_SOURCE_DIR}/redistributable_bin/osx/libsteam_api.dylib
    )
elseif(UNIX)
    target_link_libraries(steamworks INTERFACE
            ${CMAKE_CURRENT_SOURCE_DIR}/redistributable_bin/linux64/libsteam_api.so
    )
endif()

# Set properties
set_target_properties(steamworks PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)

# Create interface target
add_library(steamworks::steamworks ALIAS steamworks)