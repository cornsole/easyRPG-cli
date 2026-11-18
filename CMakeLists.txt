cmake_minimum_required(VERSION 4.5)
project("easyRPG-cli")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

include_directories(include)

set(SOURCES
    src/main.cpp
    src/game.cpp
)

add_executable(main ${SOURCES})

# target_link_libraries(main m)
