cmake_minimum_required(VERSION 3.30)
project(projects)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "D:/CLion 2024.3/SFML-2.6.2/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)


add_executable(projects main.cpp)

target_link_libraries(projects sfml-graphics sfml-window sfml-system)