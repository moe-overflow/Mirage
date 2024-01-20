
if(WIN32)
    target_compile_definitions(mirage PRIVATE MIRAGE_PLATFORM_WINDOWS)
endif()

add_executable(sandbox

        src/sandbox_application.cpp

)

target_link_libraries(sandbox PRIVATE mirage)


