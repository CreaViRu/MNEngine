add_executable(MNEngineRuntime 
    src/main.cpp
)

target_link_libraries(MNEngineRuntime PRIVATE MNEngineCore)

if(WIN32)
    add_custom_command(TARGET MNEngineRuntime POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:MNEngineRuntime>
        $<TARGET_FILE_DIR:MNEngineRuntime>
        COMMAND_EXPAND_LISTS
    )
endif()
