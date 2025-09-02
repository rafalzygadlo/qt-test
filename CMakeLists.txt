cmake_minimum_required(VERSION 3.16)
project(MyQtApp)


#set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC OFF)  # nie używamy .ui
set(CMAKE_AUTORCC ON)
set(CMAKE_WIN32_EXECUTABLE TRUE)


set(CMAKE_PREFIX_PATH "C:/Qt/6.9.2/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS Core Widgets Sql REQUIRED)

set(SOURCES
    main.cpp
    db.cpp
    view/login/loginView.cpp
    view/main/mainView.cpp
    model/baseModel.cpp
)

set(HEADERS
    db.h
    view/main/mainView.h
    view/login/loginView.h
    model/baseModel.h
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/model
    ${CMAKE_CURRENT_SOURCE_DIR}/view
)


add_executable(MyQtApp ${SOURCES} ${HEADERS})
target_link_libraries(MyQtApp Qt6::Core Qt6::Widgets Qt6::Sql)

set_target_properties(MyQtApp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)