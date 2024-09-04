project("core")

#-------------------------------------------------------------------------------
# define sources
set(CORE_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Paths.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Settings.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/SystemConf.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/LocaleES.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Log.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ImageIO.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Scripting.h

    ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Misc.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Vector2i.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Vector2f.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Vector3f.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Vector4f.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Transform4x4f.h

    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/StringUtil.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/Delegate.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/Randomizer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/StringListLock.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/ThreadPool.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/TimeUtil.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/md5.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/ZipFile.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/zip_file.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/HtmlColor.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/FileSystemUtil.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/Platform.h

    ${CMAKE_CURRENT_SOURCE_DIR}/src/resources/ResourceManager.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/resources/TextureResource.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/resources/TextureData.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/resources/TextureDataManager.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/resources/Font.h

    ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/GlExtensions.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/Renderer_GL21.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/Renderer_GLES10.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/Renderer_GLES20.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/Renderer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/Shader.h
)

set(CORE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Paths.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Settings.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/SystemConf.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/LocaleES.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Log.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ImageIO.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Scripting.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Misc.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Vector2i.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Vector2f.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Vector3f.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Vector4f.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Transform4x4f.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/StringUtil.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/Randomizer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/StringListLock.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/ThreadPool.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/TimeUtil.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/md5.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/ZipFile.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/HtmlColor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/FileSystemUtil.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/Platform.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/resources/ResourceManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/resources/TextureResource.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/resources/TextureData.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/resources/TextureDataManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/resources/Font.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/GlExtensions.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/Renderer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/Renderer_GL21.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/Renderer_GLES10.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/Renderer_GLES20.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/renderers/Shader.cpp
)

#-------------------------------------------------------------------------------
# define target
include_directories(${COMMON_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/src)
add_library(core ${CORE_SOURCES} ${CORE_HEADERS})
target_link_libraries(core ${COMMON_LIBRARIES})
