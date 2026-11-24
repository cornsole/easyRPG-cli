cmake_minimum_required(VERSION 4.5)
project("easyRPG-cli")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(CURSES_NEED_NCURSES TRUE)
set(CURSES_NEED_WIDE TRUE)
find_package(Curses REQUIRED)




set(SOURCES
src/main.cpp
src/jsonParser.cpp
# src/screen.cpp
# src/game.cpp
)

# main
add_executable(main ${SOURCES})

target_include_directories(main PRIVATE
    include
    ${CURSES_INCLUDE_DIRS}
)

target_link_libraries(main PRIVATE
    ${CURSES_LIBRARIES}
)

# test
add_executable(test src/screen.cpp)

target_include_directories(test PRIVATE
    include
    ${CURSES_INCLUDE_DIRS}
)

target_link_libraries(test PRIVATE
    ${CURSES_LIBRARIES}
)
