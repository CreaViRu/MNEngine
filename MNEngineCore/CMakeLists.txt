find_package(SDL3 CONFIG REQUIRED)
find_package(SDL3_image CONFIG REQUIRED)
find_package(SDL3_ttf CONFIG REQUIRED)
find_package(SDL3_mixer CONFIG REQUIRED)

add_library(MNEngineCore STATIC
    include/MNEngineCore/Core.hpp
    include/MNEngineCore/Window.hpp
    src/Window.cpp
)

target_link_libraries(MNEngineCore PUBLIC EngineCompilerFlags)

target_include_directories(MNEngineCore 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(MNEngineCore PUBLIC 
    SDL3::SDL3
    SDL3_image::SDL3_image
    SDL3_ttf::SDL3_ttf
    SDL3_mixer::SDL3_mixer
)