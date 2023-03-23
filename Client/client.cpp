//
// Created by black on 2023/3/16.
//

// You may need to build the project (run Qt uic code generator) to get "ui_client.h" resolved

#include "client.h"
#include "config.h"
#include "ui_client.h"
#include <QDebug>

client::client(QWidget *parent) : QWidget(parent), ui(new Ui::client) {
    qDebug() << "client::client";
    ui->setupUi(this);
    personBasicInfo = nullptr;
    personCourseInfo = nullptr;
    personScoreInfo = nullptr;
}

client::~client() {
    delete ui;
    delete personBasicInfo;
    delete personCourseInfo;
    delete personScoreInfo;
    personBasicInfo=nullptr;
    personScoreInfo=nullptr;
    personCourseInfo=nullptr;
}
void client::on_pushButton_basic_client_clicked() {
    if (personBasicInfo == nullptr) {
        personBasicInfo = new person_basic_info;
    } else {
        delete personBasicInfo;
        personBasicInfo = new person_basic_info;
    }
    personBasicInfo->show();
}
void client::on_pushButton_course_client_clicked() {
    if (personCourseInfo == nullptr) {
        personCourseInfo = new person_course_info;
    } else {
        delete personCourseInfo;
        personCourseInfo = new person_course_info;
    }
    personCourseInfo->show();
}
void client::on_pushButton_score_client_clicked() {
    if (personScoreInfo == nullptr) {
        personScoreInfo = new person_score_info;
    } else {
        delete personScoreInfo;
        personScoreInfo = new person_score_info;
    }
    personScoreInfo->show();
}
void client::on_pushButton_back_client_clicked() {
    this->hide();
}
