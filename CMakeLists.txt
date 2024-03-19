cmake_minimum_required(VERSION 3.14)

project(QmlPluginExample VERSION 1.0.0 LANGUAGES CXX)

#https://marssola.github.io/dev/2021/07/29/create-qml-plugins-with-cmake.html
#https://doc.qt.io/qtcreator/creator-qml-modules-with-plugins.html#importing-qml-modules
#https://doc.qt.io/qt-6/qtqml-modules-qmldir.html

#qmlplugindump -nonrelocatable User.Register 1.0 plugin/bin/qml >  plugin/bin/qml/User/Register/plugins.qmltypes

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QT_DEBUG_PLUGINS ON)


find_package(QT NAMES Qt5 COMPONENTS Core Quick Qml REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick QuickControls2 REQUIRED)

list(APPEND QML_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/qml")
set(QML_IMPORT_PATH "${QML_DIRS}" CACHE STRING "Qt extra qml import paths")

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
  PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/src/c++/main.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/src/qml/qml.qrc
)



target_compile_definitions(${PROJECT_NAME}
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Quick
        Qt${QT_VERSION_MAJOR}::QuickControls2
        Qt${QT_VERSION_MAJOR}::Qml
)
