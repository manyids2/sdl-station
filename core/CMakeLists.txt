project("core")

#-------------------------------------------------------------------------------
# define sources
set(CORE_HEADERS
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/Settings.h
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/Renderer.h
)
set(CORE_SOURCES
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/Settings.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/GlExtensions.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/GlExtensions.h
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/Renderer.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/Renderer_GL21.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/Renderer_GL21.h
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/Renderer_GLES10.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/Renderer_GLES10.h
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/Renderer_GLES20.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/Renderer_GLES20.h
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/Renderer.h
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/Shader.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/Shader.h
)

#-------------------------------------------------------------------------------
# define target
include_directories(${COMMON_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/src)
add_library(core ${CORE_SOURCES} ${CORE_HEADERS})
target_link_libraries(core ${COMMON_LIBRARIES})
