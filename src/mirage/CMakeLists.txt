include(${CMAKE_SOURCE_DIR}/cmake/CPM.cmake)

add_library(
        mirage
        STATIC

        application.cpp
        application.hpp
        entry_point.hpp
        exception.hpp
        window.cpp
        window.hpp

        event_system/event.hpp
        event_system/event_handler.hpp
        event_system/key_event.hpp
        event_system/mouse_event.hpp
        event_system/window_event.hpp

        utility/log.cpp
        utility/log.hpp

        utility/callback_functions.hpp
        utility/callback_functions.cpp

        graphics/shader.cpp
        graphics/shader.hpp
        graphics/buffer.cpp
        graphics/buffer.hpp
        graphics/shader_program.cpp
        graphics/shader_program.hpp
        graphics/renderer.cpp
        graphics/renderer.hpp


)

include(${CMAKE_SOURCE_DIR}/cmake/system_link.cmake)

target_link_system_libraries(
        mirage
        PUBLIC glfw
        PUBLIC glad
        PUBLIC spdlog::spdlog
)


target_include_directories(mirage
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)


if(WIN32)
        add_compile_definitions(MIRAGE_PLATFORM_WINDOWS)
        #target_compile_definitions(mirage PRIVATE MIRAGE_PLATFORM_WINDOWS)
        #target_compile_definitions(mirage PRIVATE MIRAGE_BUILD_DLL)
endif()



#target_link_libraries()
