project(test)

cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

set(
    SOURCES
    sources/main.cpp
)

include_directories(libraries/sol)

include_directories(/usr/local/include/luajit-2.1)

include_directories(libraries/glm)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} luajit-5.1)
