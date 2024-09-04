cmake_minimum_required(VERSION 3.10)

set(OpenGL_GL_PREFERENCE LEGACY)

option(GLES "Set to ON if targeting Embedded OpenGL" ${GLES})
option(GLES2 "Set to ON if targeting OpenGL ES 2.0" ${GLES2})
option(GL "Set to ON if targeting Desktop OpenGL" ${GL})

project(sdl-station)

#-------------------------------------------------------------------------------
#add local find scripts to CMAKE path
LIST(APPEND CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}/CMake/Utils
    ${CMAKE_CURRENT_SOURCE_DIR}/CMake/Packages
)

#-------------------------------------------------------------------------------
#set up OpenGL system variable
if(GLES)
    set(GLSystem "Embedded OpenGL" CACHE STRING "The OpenGL system to be used")
elseif(GLES2)
    set(GLSystem "OpenGL ES 2.0" CACHE STRING "The OpenGL system to be used")
elseif(GL)
    set(GLSystem "Desktop OpenGL" CACHE STRING "The OpenGL system to be used")
#check if we're running on olinuxino / odroid / etc
elseif(EXISTS "${CMAKE_FIND_ROOT_PATH}/usr/lib/libMali.so" OR
    EXISTS "${CMAKE_FIND_ROOT_PATH}/usr/lib/libmali.so" OR # batocera
    EXISTS "${CMAKE_FIND_ROOT_PATH}/usr/lib/arm-linux-gnueabihf/libMali.so" OR
    EXISTS "${CMAKE_FIND_ROOT_PATH}/usr/lib/aarch64-linux-gnu/libMali.so" OR
    EXISTS "${CMAKE_FIND_ROOT_PATH}/usr/lib/arm-linux-gnueabihf/mali-egl/libmali.so" OR
    EXISTS "${CMAKE_FIND_ROOT_PATH}/usr/lib/arm-linux-gnueabihf/libmali.so")
    MESSAGE("libMali.so found")
    set(GLSystem "Embedded OpenGL" CACHE STRING "The OpenGL system to be used")
else()
    set(GLSystem "Desktop OpenGL" CACHE STRING "The OpenGL system to be used")
endif(GLES)

set_property(CACHE GLSystem PROPERTY STRINGS "Desktop OpenGL" "Embedded OpenGL")

#finding necessary packages
#-------------------------------------------------------------------------------
if(${GLSystem} MATCHES "Desktop OpenGL")
    find_package(OpenGL REQUIRED)
elseif(${GLSystem} MATCHES "OpenGL ES 2.0")
    find_package(OpenGLES2 REQUIRED)
else()
    find_package(OpenGLES REQUIRED)
endif()
find_package(SDL2 REQUIRED)
find_package(Freetype REQUIRED)
find_package(FreeImage REQUIRED)
find_package(ALSA REQUIRED)

find_package(udev)
if(UDEV_FOUND)
  MESSAGE("udev found. guns enabled")
  add_definitions(-DHAVE_UDEV)
else()
  MESSAGE("udev not found. guns will be disabled")
endif()


#-------------------------------------------------------------------------------
#set up compiler flags and excutable names

if(CMAKE_COMPILER_IS_GNUCXX)
    #check for G++ 4.7+
    execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion OUTPUT_VARIABLE G++_VERSION)
    if (G++_VERSION VERSION_LESS 4.7)
            message(SEND_ERROR "You need at least G++ 4.7 to compile sdl-station!")
    endif()

    #set up compiler flags for GCC
if (CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wno-attributes -O0") #support C++14 for std::, optimize
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -O0")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wno-attributes -O3") #support C++14 for std::, optimize
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -O3")  #-s = strip binary
endif()
endif()

if(${GLSystem} MATCHES "Desktop OpenGL")
    add_definitions(-DUSE_OPENGL_21)
elseif(${GLSystem} MATCHES "OpenGL ES 2.0")
    add_definitions(-DUSE_OPENGLES_20)
else()
    add_definitions(-DUSE_OPENGLES_10)
endif()

#-------------------------------------------------------------------------------
#add include directories
set(COMMON_INCLUDE_DIRS
    ${SDL2_INCLUDE_DIR}
    ${FREETYPE_INCLUDE_DIRS}
    ${FreeImage_INCLUDE_DIRS}
    ${ALSA_INCLUDE_DIRS}
)

if(${GLSystem} MATCHES "Desktop OpenGL")
    LIST(APPEND COMMON_INCLUDE_DIRS
        ${OPENGL_INCLUDE_DIR}
    )
elseif(${GLSystem} MATCHES "OpenGL ES 2.0")
    LIST(APPEND COMMON_INCLUDE_DIRS
        ${OPENGLES2_INCLUDE_DIR}
    )
else()
    LIST(APPEND COMMON_INCLUDE_DIRS
        ${OPENGLES_INCLUDE_DIR}
    )
endif()

#-------------------------------------------------------------------------------
#define libraries and directories

set(COMMON_LIBRARIES
    ${SDL2_LIBRARY}
    ${FREETYPE_LIBRARIES}
    ${FreeImage_LIBRARIES}
    ${ALSA_LIBRARY}
)

if(UDEV_FOUND)
 LIST(APPEND COMMON_LIBRARIES
    ${UDEV_LIBRARY}
      )
endif()

if(${GLSystem} MATCHES "Desktop OpenGL")
    LIST(APPEND COMMON_LIBRARIES
        ${OPENGL_LIBRARIES}
    )
elseif(${GLSystem} MATCHES "OpenGL ES 2.0")
    LIST(APPEND COMMON_LIBRARIES
        EGL
        ${OPENGLES2_LIBRARIES}
    )
else()
    LIST(APPEND COMMON_LIBRARIES
        EGL
        ${OPENGLES_LIBRARIES}
    )
endif()

# set(dir ${CMAKE_CURRENT_SOURCE_DIR}/build)
# set(EXECUTABLE_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
# set(LIBRARY_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)

#-------------------------------------------------------------------------------
# Add core to common includes

LIST(APPEND COMMON_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/core/src)

#-------------------------------------------------------------------------------
# add each component

add_subdirectory("core")
add_subdirectory("app")
