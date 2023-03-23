//
// Created by black on 2023/3/16.
//

// You may need to build the project (run Qt uic code generator) to get "ui_server.h" resolved

#include "server.h"
#include "ui_server.h"


server::server(QWidget *parent) : QWidget(parent), ui(new Ui::server) {
    ui->setupUi(this);
    stuBasicInfoManage=nullptr;
    stuLoginInfo=nullptr;
    adminInfoManage=nullptr;
    courseInfoManage=nullptr;
    scoreInfoManage=nullptr;
}

server::~server() {
    delete ui;
    delete stuBasicInfoManage;
    delete stuLoginInfo;
    delete adminInfoManage;
    delete courseInfoManage;
    delete scoreInfoManage;
}
void server::on_pushButton_basic_info_clicked() {
//    this->hide();
    NEW_OBJECT(stu_basic_info_manage,stuBasicInfoManage)
    stuBasicInfoManage->show();
}
void server::on_pushButton_course_clicked() {
    NEW_OBJECT(course_info_manage,courseInfoManage)
    courseInfoManage->show();
}
void server::on_pushButton_login_info_clicked() {
    NEW_OBJECT(stu_Login_Info,stuLoginInfo)
    stuLoginInfo->show();
}
void server::on_pushButton_score_info_clicked() {
    NEW_OBJECT(score_info_manage,scoreInfoManage)
    scoreInfoManage->show();
}
void server::on_pushButton_manager_info_clicked() {
    NEW_OBJECT(admin_info_manage,adminInfoManage)
    adminInfoManage->show();
}
void server::on_pushButton_back_clicked() {
    this->hide();
}
