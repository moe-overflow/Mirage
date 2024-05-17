include(${CMAKE_SOURCE_DIR}/cmake/CPM.cmake)

set(
        PCH
        ${CMAKE_CURRENT_SOURCE_DIR}/pch.hpp
)

set(
        HEADER_FILES
        ${PCH}
        application.hpp
        entry_point.hpp
        exception.hpp
        window.hpp

        event_system/event.hpp
        event_system/event_handler.hpp
        event_system/key_event.hpp
        event_system/mouse_event.hpp
        event_system/window_event.hpp

        utility/log.hpp
        utility/callback_functions.hpp


        graphics/buffer.hpp
        graphics/renderer.hpp
        graphics/shader.hpp
        graphics/shader_program.hpp
        graphics/vertex_array.hpp

)

set(
        SOURCE_FILES

        ${HEADER_FILES}

        application.cpp
        window.cpp

        utility/log.cpp
        utility/callback_functions.cpp

        graphics/index_buffer.cpp
        graphics/renderer.cpp
        graphics/shader.cpp
        graphics/shader_program.cpp
        graphics/vertex_array.cpp
        graphics/vertex_buffer.cpp
)



add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})


include(${CMAKE_SOURCE_DIR}/cmake/system_link.cmake)

target_link_system_libraries(
        ${PROJECT_NAME}
        PUBLIC glfw
        PUBLIC glad
        PUBLIC spdlog::spdlog
)


target_include_directories(
        ${PROJECT_NAME}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_precompile_headers(${PROJECT_NAME} PRIVATE ${PCH})

