project("sdl-station")

#-------------------------------------------------------------------------------
# define sources
set(ES_HEADERS)
set(ES_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

#-------------------------------------------------------------------------------
# define target
include_directories(${COMMON_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/src)
add_executable(sdl-station ${ES_SOURCES} ${ES_HEADERS})
target_link_libraries(sdl-station ${COMMON_LIBRARIES} core)
