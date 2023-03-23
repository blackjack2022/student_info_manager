cmake_minimum_required(VERSION 3.24)
project(students_info_management)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/app_install/QT/5.6/mingw49_32")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Sql
        REQUIRED)

add_executable(students_info_management main.cpp mainwindow/mainwindow.cpp mainwindow/mainwindow.h mainwindow/mainwindow.ui Client/client.cpp Client/client.h Client/client.ui Server/server.cpp Server/server.h Server/server.ui config.h config.cpp Server/stu_basic_info_manage.cpp Server/stu_basic_info_manage.h Server/stu_basic_info_manage.ui Server/view_all_stu_info.cpp Server/view_all_stu_info.h Server/view_all_stu_info.ui Server/stu_login_info.cpp Server/stu_login_info.h Server/stu_login_info.ui Server/admin_info_manage.cpp Server/admin_info_manage.h Server/admin_info_manage.ui Server/course_info_manage.cpp Server/course_info_manage.h Server/course_info_manage.ui Server/score_info_manage.cpp Server/score_info_manage.h Server/score_info_manage.ui Server/MyQSqlTableModel.cpp Server/MyQSqlTableModel.h Client/person_basic_info.cpp Client/person_basic_info.h Client/person_basic_info.ui Client/person_course_info.cpp Client/person_course_info.h Client/person_course_info.ui Client/person_score_info.cpp Client/person_score_info.h Client/person_score_info.ui)
target_link_libraries(students_info_management
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Sql
        )
target_include_directories(students_info_management PRIVATE "${/}")
target_include_directories(students_info_management PRIVATE "${CMAKE_BINARY_DIR}/students_info_management_autogen/include")
if (WIN32)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
