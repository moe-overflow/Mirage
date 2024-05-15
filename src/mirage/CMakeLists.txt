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

        graphics/buffer.hpp
        graphics/index_buffer.cpp
        graphics/renderer.cpp
        graphics/renderer.hpp
        graphics/shader.cpp
        graphics/shader.hpp
        graphics/shader_program.cpp
        graphics/shader_program.hpp
        graphics/vertex_array.cpp
        graphics/vertex_array.hpp
        graphics/vertex_buffer.cpp

)

include(${CMAKE_SOURCE_DIR}/cmake/system_link.cmake)

target_link_system_libraries(
        mirage
        PUBLIC glfw
        PUBLIC glad
        PUBLIC spdlog::spdlog
)


target_include_directories(
        mirage
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

