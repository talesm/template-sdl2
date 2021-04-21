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

# Dear Imgui
FetchContent_Declare(
  DearImgui
  GIT_REPOSITORY https://github.com/ocornut/imgui.git
  GIT_TAG        v1.82
)

#Make content available
FetchContent_MakeAvailable(SDL2pp DearImgui)

# Basic configuration
add_library(config INTERFACE)
target_include_directories(config INTERFACE include ${SDL2PP_INCLUDE_DIRS})
target_link_libraries(config INTERFACE ${SDL2PP_LIBRARIES})
target_compile_features(config INTERFACE cxx_std_20)

# Dear imgui library
FetchContent_GetProperties(DearImgui
  SOURCE_DIR DearImgui_SOURCE_DIR
)
add_library(DearImguiLib
  ${DearImgui_SOURCE_DIR}/imgui_demo.cpp
  ${DearImgui_SOURCE_DIR}/imgui_draw.cpp
  ${DearImgui_SOURCE_DIR}/imgui_tables.cpp
  ${DearImgui_SOURCE_DIR}/imgui_widgets.cpp
  ${DearImgui_SOURCE_DIR}/backends/imgui_impl_sdl.cpp
  external/Imgui_sdl2_renderer/imgui_impl_sdl_renderer.cpp  # Uncomment if using sdl2 renderer
  # ${DearImgui_SOURCE_DIR}/backends/imgui_impl_opengl2.cpp # Uncomment if using opengl2
  # ${DearImgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp # Uncomeent if using opengl3
  ${DearImgui_SOURCE_DIR}/imgui.cpp
)
target_include_directories(DearImguiLib PUBLIC 
  ${DearImgui_SOURCE_DIR}
  ${DearImgui_SOURCE_DIR}/backends
  external/Imgui_sdl2_renderer/
)
target_link_libraries(DearImguiLib PUBLIC config)

# Hello world
add_executable(helloworld WIN32
  src/main.cpp
)
target_link_libraries(helloworld
  PRIVATE config DearImguiLib
)
