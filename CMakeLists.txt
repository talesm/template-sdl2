cmake_minimum_required(VERSION 3.16)
project(MyProjectNameHere)
include(FetchContent)

# SDL2pp
FetchContent_Declare(
  SDL2pp
  GIT_REPOSITORY https://github.com/libSDL2pp/libSDL2pp.git
  GIT_TAG        0.16.1
)
SET(SDL2PP_WITH_IMAGE ON) # if you need SDL_image support
SET(SDL2PP_WITH_MIXER ON) # if you need SDL_mixer support
SET(SDL2PP_WITH_TTF ON) # if you need SDL_ttf support

#Make content available
FetchContent_MakeAvailable(SDL2pp)

# Basic configuration
add_library(config INTERFACE)
target_include_directories(config INTERFACE include ${SDL2PP_INCLUDE_DIRS})
target_link_libraries(config INTERFACE ${SDL2PP_LIBRARIES})
target_compile_features(config INTERFACE cxx_std_20)

# Hello world
add_executable(helloworld WIN32
  src/main.cpp
)
target_link_libraries(helloworld
  PRIVATE config
)
