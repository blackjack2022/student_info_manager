//
// Created by black on 2023/3/16.
//

#ifndef STUDENTS_INFO_MANAGEMENT_CONFIG_H
#define STUDENTS_INFO_MANAGEMENT_CONFIG_H
#include <QString>
#include <QVariantList>
#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
//数据库
extern QString database_name;
extern QString database_driver;
extern QString host_name;
extern QString user_name;
extern QString database_password;
extern QString login_name;
extern QString login_password;
extern QSqlDatabase *db;
extern QString client_stu_id;

#define NEW_OBJECT(CLASS_NAME,OBJECT_NAME) \
    if(OBJECT_NAME){\
delete OBJECT_NAME;\
OBJECT_NAME=nullptr;\
}\
OBJECT_NAME=new CLASS_NAME;
#endif//STUDENTS_INFO_MANAGEMENT_CONFIG_H
