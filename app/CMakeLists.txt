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


#-------------------------------------------------------------------------------
# set up CPack install stuff so `make install` does something useful

install(TARGETS sdl-station
    RUNTIME
    DESTINATION bin)

INCLUDE(InstallRequiredSystemLibraries)

SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A vst front-end")
SET(CPACK_PACKAGE_DESCRIPTION "sdl-station is a front-end for vst plugins")

SET(CPACK_RESOURCE_FILE LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.md")
SET(CPACK_RESOURCE_FILE README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")

SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "manyids2 <manyids2@gmail.com>")
SET(CPACK_DEBIAN_PACKAGE_SECTION "misc")
SET(CPACK_DEBIAN_PACKAGE_PRIORITY "extra")
SET(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6, libsdl2-2.0-0, libfreeimage3, libfreetype6, libcurl3, libasound2")
SET(CPACK_DEBIAN_PACKAGE_BUILDS_DEPENDS "debhelper (>= 8.0.0), cmake, g++ (>= 4.8), libsdl2-dev, libsdl2-mixer-dev, libfreeimage-dev, libfreetype6-dev, libcurl4-openssl-dev, libasound2-dev, libgl1-mesa-dev, libgl1-mesa-dev")

SET(CPACK_PACKAGE_VENDOR "sdl-station.org")
SET(CPACK_PACKAGE_VERSION "0.1.0~rc1")
SET(CPACK_PACKAGE_VERSION_MAJOR "0")
SET(CPACK_PACKAGE_VERSION_MINOR "1")
SET(CPACK_PACKAGE_VERSION_PATCH "0")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "sdl-station_${CMAKE_PACKAGE_VERSION}")
SET(CPACK_PACKAGE_EXECUTABLES "sdl-station" "sdl-station")

SET(CPACK_GENERATOR "TGZ;DEB")

INCLUDE(CPack)
