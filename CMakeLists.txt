cmake_minimum_required(VERSION 3.20)

project(sfml_playground LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(WINDOWS_SFML_DIR $ENV{WINDOWS_SFML_DIR})
set(LINUX_SFML_DIR $ENV{LINUX_SFML_DIR})

add_executable(${PROJECT_NAME} main.cpp
GameEngine.cpp
EntityManager.cpp
Entity.cpp
Components.cpp
Systems.cpp)

target_compile_options(${PROJECT_NAME} PRIVATE -g)

# target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)


target_include_directories(${PROJECT_NAME} PRIVATE  ${PROJECT_SOURCE_DIR}/include)


if(WIN32)
  target_include_directories(${PROJECT_NAME} PRIVATE  ${WINDOWS_SFML_DIR}/include/)
elseif(UNIX)
  target_include_directories(${PROJECT_NAME} PRIVATE  ${LINUX_SFML_DIR}/include/)
endif()


if(WIN32)
  target_link_directories(${PROJECT_NAME} PRIVATE  ${WINDOWS_SFML_DIR}/lib)
elseif(UNIX)
  target_link_directories(${PROJECT_NAME} PRIVATE  ${LINUX_SFML_DIR}/lib)
endif()


if(WIN32)
  target_link_libraries(${PROJECT_NAME} PRIVATE
    ${WINDOWS_SFML_DIR}/lib/sfml-system.lib
    ${WINDOWS_SFML_DIR}/lib/sfml-window.lib
    ${WINDOWS_SFML_DIR}/lib/sfml-graphics.lib)
elseif(UNIX)
    target_link_libraries(${PROJECT_NAME} PRIVATE
    -lsfml-system
    -lsfml-window
    -lsfml-graphics)
endif()
