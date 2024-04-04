cmake_minimum_required(VERSION 3.27)
project(lab_01)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
include_directories(. inc)
add_executable(
        lab_01
        src/main.cpp
        src/mainwindow.cpp
        src/request.cpp
        src/my_error.cpp
        src/points.cpp
        src/point.cpp
        src/edges.cpp
        src/edge.cpp
        src/figure.cpp
        src/figure_draw.cpp
)
target_link_libraries(lab_01
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

