cmake_minimum_required(VERSION 3.20)

project(sfml_playground LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(ROOT_PROJECT_DIR $ENV{ROOT_PROJECT_DIR})

add_executable(${PROJECT_NAME} main.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE -g)

# target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_include_directories(${PROJECT_NAME} PRIVATE  ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE  ${ROOT_PROJECT_DIR}/include/)
target_link_directories(${PROJECT_NAME} PRIVATE  ${ROOT_PROJECT_DIR}/lib)
target_link_libraries(${PROJECT_NAME} PRIVATE
 ${ROOT_PROJECT_DIR}/lib/sfml-system.lib
 ${ROOT_PROJECT_DIR}/lib/sfml-window.lib
 ${ROOT_PROJECT_DIR}/lib/sfml-graphics.lib)
