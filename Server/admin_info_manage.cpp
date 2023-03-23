//
// Created by black on 2023/3/19.
//

// You may need to build the project (run Qt uic code generator) to get "ui_admin_info_manage.h" resolved

#include "admin_info_manage.h"
#include "ui_admin_info_manage.h"


admin_info_manage::admin_info_manage(QWidget *parent) : QWidget(parent), ui(new Ui::admin_info_manage) {
    ui->setupUi(this);
}

admin_info_manage::~admin_info_manage() {
    delete ui;
}
void admin_info_manage::on_pushButton_delete_admin_clicked() {
    if(db->open()){
        qDebug()<<"connected";
    }else{
        qDebug()<<"fail to connect";
    }
    input_id = ui->lineEdit_account->text();
    pre_exec = QString("SELECT account FROM admin_account WHERE account='%1'").arg(input_id);
    if (que.exec(pre_exec) && que.size() > 0) {
        exec = QString("DELETE FROM admin_account WHERE account='%1'").arg(input_id);
        if (que.exec(exec)) {
            QMessageBox::information(this, "提示", "删除成功！");
        } else {
            QMessageBox::critical(this, "错误", "删除失败！");
        }
    }else {
        QMessageBox::warning(this, "警告", "账号输入错误！");
    }
}
void admin_info_manage::on_pushButton_update_admin_clicked() {
    if(db->open()){
        qDebug()<<"connected";
    }else{
        qDebug()<<"fail to connect";
    }
    input_id = ui->lineEdit_account->text();
    input_password = ui->lineEdit_password->text();
    pre_exec = QString("SELECT account FROM admin_account WHERE account='%1'").arg(input_id);
    if (que.exec(pre_exec) && que.size() > 0) {
        exec = QString("UPDATE admin_account SET password='%1' WHERE account='%2'").arg(input_password).arg(input_id);
        que.clear();
        qDebug() << exec;
        qDebug() << que.size();
        if (que.exec(exec)) {
            QMessageBox::information(this, "提示", "修改成功！");
        } else {
            QMessageBox::critical(this, "错误", "修改失败！");
        }
    }else {
        QMessageBox::warning(this, "警告", "账号输入错误！");
    }
}
void admin_info_manage::on_pushButton_check_admin_clicked() {
    if(db->open()){
        qDebug()<<"connected";
    }else{
        qDebug()<<"fail to connect";
    }
    input_id = ui->lineEdit_account->text();
    exec = QString("SELECT password FROM admin_account WHERE account='%1'").arg(input_id);
    que.clear();
    qDebug() << exec;
    if (que.exec(exec)&&que.size()) {
        que.next();
        ui->lineEdit_password->setText(que.value(0).toString());
    } else {
        QMessageBox::critical(this, "错误", "账号输入错误！");
    }
}
void admin_info_manage::on_pushButton_clear_admin_clicked() {
    ui->lineEdit_account->clear();
    ui->lineEdit_password->clear();
}
void admin_info_manage::on_pushButton_back_admin_clicked() {
    this->hide();
}
void admin_info_manage::on_pushButton_add_admin_clicked() {
    if(db->open()){
        qDebug()<<"connected";
    }else{
        qDebug()<<"fail to connect";
    }
    input_id = ui->lineEdit_account->text();
    input_password = ui->lineEdit_password->text();
    que.clear();
    exec = QString("INSERT INTO admin_account(account,password) VALUES('%1','%2')").arg(input_id).arg(input_password);
    qDebug() << exec;
    if (que.exec(exec)) {
        QMessageBox::information(this, "提示", "添加成功！");
    } else {
        QMessageBox::critical(this, "错误", "添加失败！");
    }
}
