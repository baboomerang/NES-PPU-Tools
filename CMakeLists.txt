cmake_minimum_required(VERSION 3.1.0)

project(helloworld)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS
    Widgets REQUIRED
    Gui REQUIRED
)

add_executable(mainprogram
    main.cpp
    menubar.cpp
)

target_link_libraries(mainprogram
    Qt5::Widgets
    Qt5::Gui
)
