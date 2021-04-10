cmake_minimum_required(VERSION 3.19)
project(GameEngine)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SDLTest_SOURCE_DIR}/bin)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
            TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_add_remote(NAME bincrafters URL https://api.bintray.com/conan/bincrafters/public-conan)

conan_cmake_configure(REQUIRES sdl2/2.0.9@bincrafters/stable sdl2_image/2.0.5@bincrafters/stable sdl2_ttf/2.0.15@bincrafters/stable libpng/1.6.37 zlib/1.2.11 GENERATORS cmake_find_package)

conan_cmake_autodetect(settings)

conan_cmake_install(PATH_OR_REFERENCE . BUILD missing SETTINGS ${settings})

find_package(sdl2)
find_package(sdl2_image)
find_package(sdl2_ttf)

add_executable(GameEngine App/main.cpp Engine/graphics/WindowManager.cpp Engine/graphics/WindowManager.h Engine/CovidEngine.h Engine/graphics/Graphics.cpp Engine/graphics/Graphics.h)

include_directories(ErrorHandling)

target_link_libraries(GameEngine PRIVATE sdl2::sdl2 sdl2_image::sdl2_image sdl2_ttf::sdl2_ttf)