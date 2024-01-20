include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CPM.cmake)

function(load_dependencies)

    CPMAddPackage(
            NAME SPDLOG
            GITHUB_REPOSITORY gabime/spdlog
            VERSION 1.12.0
    )

    CPMAddPackage(
            NAME GLFW
            GITHUB_REPOSITORY glfw/glfw
            GIT_TAG 3.3.9
    )

    #CPMAddPackage(
    #    NAME GLM
    #    GITHUB_REPOSITORY icaven/glm
    #    GIT_TAG 0.9.3.2
    #)

    #CPMAddPackage(
    #    NAME PYBIND11
    #    GITHUB_REPOSITORY pybind/pybind11
    #    VERSION 2.11.1
    #)

    CPMAddPackage(
            NAME GOOGLETEST
            GITHUB_REPOSITORY google/googletest
            VERSION 1.14.0
    )

    CPMAddPackage(
            NAME IMGUI
            GITHUB_REPOSITORY ocornut/imgui
            VERSION 1.90
    )


endfunction()