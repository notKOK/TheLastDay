cmake_minimum_required(VERSION 3.17)
project(kursuck)

set(SFML_DIR "C:/SFML")

find_package(SFML 2.5.1 COMPONENTS graphics window system)

add_executable(kursuck main.cpp menu.cpp menu.h
        units.cpp units.h)

target_link_libraries(kursuck sfml-graphics sfml-audio)
