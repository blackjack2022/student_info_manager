//
// Created by black on 2023/3/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_person_basic_info.h" resolved

#include "person_basic_info.h"
#include "../config.h"
#include "ui_person_basic_info.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QWidget>


person_basic_info::person_basic_info(QWidget *parent) : QWidget(parent), ui(new Ui::person_basic_info) {
    ui->setupUi(this);
    QSqlQuery que;
    QString exec = QString("SELECT name,major,stu_id FROM my_class WHERE stu_id='%1'").arg(client_stu_id);
    qDebug()<<client_stu_id;
    if (que.exec(exec) && db->isOpen()) {
        qDebug() << "执行成功！";
    }
    qDebug() << que.size();
    que.next();
    ui->textBrowser_stu_id->setText(client_stu_id);
    ui->textBrowser_name->setText(que.value(0).toString());
    ui->textBrowser_stu_id->setText(que.value(2).toString());
    ui->textBrowser_major->setText(que.value(1).toString());
}

person_basic_info::~person_basic_info() {
    delete ui;
}
