cmake_minimum_required(VERSION 4.3)

project(Engine CXX)

add_library(EngineCompilerFlags INTERFACE)

target_compile_features(EngineCompilerFlags INTERFACE cxx_std_23)

target_compile_options(EngineCompilerFlags INTERFACE
    $<$<CXX_COMPILER_ID:MSVC>:/W4;/permissive->
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall;-Wextra;-pedantic-errors>
)

add_subdirectory(MNEngineCore)
add_subdirectory(MNEngineRuntime)