cmake_minimum_required(VERSION 3.15)
project(arithmetic-tui LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Catalina libc++ fixes for clangd
if(APPLE)
  set(CMAKE_OSX_SYSROOT "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -isysroot ${CMAKE_OSX_SYSROOT}")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -isysroot ${CMAKE_OSX_SYSROOT}")
endif()

find_package(ftxui CONFIG REQUIRED)
add_executable(main main.cpp)
target_link_libraries(main PRIVATE ftxui::screen ftxui::dom ftxui::component)
