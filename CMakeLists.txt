cmake_minimum_required(VERSION 3.16)
project(MyProjectNameHere)

# Basic configuration
add_library(config INTERFACE)
target_include_directories(config INTERFACE include)
target_compile_features(config INTERFACE cxx_std_20)

# Hello world
add_executable(helloworld WIN32
  src/main.cpp
)
target_link_libraries(helloworld
  PRIVATE config
)
