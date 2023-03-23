//
// Created by black on 2023/3/15.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Mainwindow.h" resolved

#include "mainwindow.h"
#include "ui_Mainwindow.h"
#include <QDebug>

Mainwindow::Mainwindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::Mainwindow) {
    qDebug() << "Mainwindow";
    ui->setupUi(this);
    ui->lineEdit_account->setText("admin");
    ui->lineEdit_password->setText("admin");

    client_stu_id = ui->lineEdit_account->text();
    to_Server = new server;
    to_Client = new client;
    ui->radioButton_server->setChecked(true);
    //    ui->radioButton_client->setChecked(true);
}

Mainwindow::~Mainwindow() {
    delete ui;
    if (to_Server) {
        delete to_Server;
        to_Server = nullptr;
    }
    if (to_Client) {
        delete to_Client;
        to_Client = nullptr;
    }
}
void Mainwindow::on_pushButton_login_clicked() {
    login_name = ui->lineEdit_account->text();
    login_password = ui->lineEdit_password->text();
    qDebug() << login_name;
    qDebug() << login_password;
    qDebug() << "Mainwindow::on_pushButton_login_clicked";
    //连接数据库操作
    if (db->open()) {
        qDebug() << "connected";
    } else {
        qDebug() << "fail to connect";
    }
    QSqlQuery que;
    bool flag = true;
    if (ui->radioButton_server->isChecked()) {
        QString test = QString("SELECT password FROM admin_account WHERE account='%1' AND password='%2'").arg(login_name).arg(login_password);// 1 or 1 = 1
        if (que.exec(test) && que.size() > 0) {
            que.next();
            to_Server = new server;
            to_Server->show();
            flag = false;
        }
    } else {
        que.clear();
        QString test = QString("SELECT password FROM student_account WHERE stu_id='%1' AND password='%2'").arg(login_name).arg(login_password);
        if (que.exec(test) && que.size() > 0) {
            client_stu_id = ui->lineEdit_account->text();
            to_Client->show();
            flag = false;
        }
    }
    if (flag) {
        QMessageBox::critical(nullptr, "错误", "账号或密码输入错误！");
    }
}
void Mainwindow::on_pushButton_reset_clicked() {
    ui->lineEdit_account->setText("");
    ui->lineEdit_password->setText("");
}
