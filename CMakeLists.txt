cmake_minimum_required(VERSION 3.10)

project(skeleton VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

# add the executable
#add_executable(skeleton src/skeleton.cpp)
#target_link_libraries(skeleton ${wxWidgets_LIBRARIES})

add_executable(
    skeleton
    src/controler/Controler.cpp
    src/MyApp.cpp
    src/view/Constant.hpp
    src/view/MyControlPanel.cpp 
    src/view/MyDrawingPanel.cpp 
    src/view/MyFrame.cpp
    src/model/Point.cpp
    src/model/Forme.cpp
    src/model/Line.cpp
    src/model/Cercle.cpp
    src/model/Dessin.cpp)

target_link_libraries(skeleton ${wxWidgets_LIBRARIES})

