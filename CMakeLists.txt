cmake_minimum_required(VERSION 3.22)
project(snake)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-O2 -Wall -Wextra -Wpedantic)
endif()

find_package(Curses REQUIRED)

include_directories(inc)

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    src/snake.cpp
    src/game.cpp
)

target_link_libraries(snake ${CURSES_LIBRARIES})


