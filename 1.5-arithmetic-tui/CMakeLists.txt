cmake_minimum_required(VERSION 3.15)
project(arithmetic-tui LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp)

# If this project uses any external libs, link them here
# find_package(fmt CONFIG REQUIRED)
# target_link_libraries(main PRIVATE fmt::fmt)
