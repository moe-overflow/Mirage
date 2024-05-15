
if(WIN32)
    target_compile_definitions(mirage PRIVATE MIRAGE_PLATFORM_WINDOWS)
endif()

add_executable(sandbox
        sandbox_application.cpp
)

set_target_properties(sandbox PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/sandbox")

include_directories(${CMAKE_SOURCE_DIR}/include)

target_include_directories(
        sandbox
        PRIVATE ${CMAKE_SOURCE_DIR}/shaders
)

target_link_libraries(sandbox
        PRIVATE mirage
)

add_custom_command(TARGET sandbox POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/shaders
        $<TARGET_FILE_DIR:sandbox>/shaders

)


