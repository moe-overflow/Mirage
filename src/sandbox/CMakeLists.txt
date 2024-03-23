
if(WIN32)
    target_compile_definitions(mirage PRIVATE MIRAGE_PLATFORM_WINDOWS)
endif()


add_executable(sandbox

        sandbox_application.cpp

)

include_directories(${CMAKE_SOURCE_DIR}/include)
#target_include_directories(sandbox PRIVATE ${CMAKE_SOURCE_DIR}/include)


target_link_libraries(sandbox PRIVATE mirage)


