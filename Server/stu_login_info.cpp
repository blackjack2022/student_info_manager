//
// Created by black on 2023/3/18.
//

// You may need to build the project (run Qt uic code generator) to get "ui_stu_Login_Info.h" resolved

#include "stu_login_info.h"
#include "ui_stu_Login_Info.h"


stu_Login_Info::stu_Login_Info(QWidget *parent) : QWidget(parent), ui(new Ui::stu_Login_Info) {
    ui->setupUi(this);
}

stu_Login_Info::~stu_Login_Info() {
    delete ui;
}
void stu_Login_Info::on_pushButton_checked_clicked() {
    if (db->open()) {
        qDebug() << "connected";
    } else {
        qDebug() << "fail to connect";
    }
    input_id = ui->lineEdit_id->text();
    exec = QString("select stu_id,password from student_account where stu_id='%1'").arg(input_id);
    que.clear();
    qDebug() << exec;
    if (que.exec(exec) && que.size()) {
        que.next();
        ui->lineEdit_password->setText(que.value(1).toString());
    } else {
        QMessageBox::critical(this, "错误", "学号输入错误！");
    }
}
void stu_Login_Info::on_pushButton_add_clicked() {
    if (db->open()) {
        qDebug() << "connected";
    } else {
        qDebug() << "fail to connect";
    }
    input_id = ui->lineEdit_id->text();
    input_password = ui->lineEdit_password->text();
    que.clear();
    exec = QString("select stu_id,name,major from my_class where stu_id ='%1'").arg(input_id);
    qDebug() << exec;
    if (que.exec(exec) && que.size()) {//size()函数对于non-select statements SQL语句返回-1，update，insert，delete为non-select statements
        que.clear();
        exec = QString("insert into student_account(password,stu_id) values('%2','%1')").arg(input_id).arg(input_password);
        qDebug() << exec;
        if (que.exec(exec)) {
            que.next();
            qDebug() << que.value(0).toString() << que.value(1).toString();
            QMessageBox::information(this, "提示", "添加成功！");
        } else {
            QMessageBox::critical(this, "错误", "添加失败！");
        }
    } else {
        QMessageBox::critical(this, "错误", "学号输入错误，请检查是否存在该学生！");
    }
}
void stu_Login_Info::on_pushButton_delete_clicked() {
    if (db->open()) {
        qDebug() << "connected";
    } else {
        qDebug() << "fail to connect";
    }
    input_id = ui->lineEdit_id->text();
    pre_exec = QString("select stu_id from student_account where stu_id='%1'").arg(input_id);
    if (que.exec(pre_exec) && que.size() > 0) {
        exec = QString("delete from student_account where stu_id='%1'").arg(input_id);
        que.clear();
        qDebug() << exec;
        if (que.exec(exec)) {
            QMessageBox::information(this, "提示", "删除成功！");
        } else {
            QMessageBox::critical(this, "错误", "删除失败！");
        }
    } else {
        QMessageBox::warning(this, "警告", "学号输入错误！");
    }
}
void stu_Login_Info::on_pushButton_upgrade_clicked() {
    if (db->open()) {
        qDebug() << "connected";
    } else {
        qDebug() << "fail to connect";
    }
    input_id = ui->lineEdit_id->text();
    input_password = ui->lineEdit_password->text();
    pre_exec = QString("select stu_id from student_account where stu_id='%1'").arg(input_id);
    if (que.exec(pre_exec) && que.size() > 0) {
        exec = QString("update student_account set password='%2' where stu_id='%1'").arg(input_id).arg(input_password);
        que.clear();
        qDebug() << exec;
        qDebug() << que.size();
        if (que.exec(exec)) {
            QMessageBox::information(this, "提示", "修改成功！");
        } else {
            QMessageBox::critical(this, "错误", "修改失败！");
        }
    }else{
        QMessageBox::warning(this, "警告", "学号输入错误！");
    }
}
void stu_Login_Info::on_pushButton_clear_clicked() {
    ui->lineEdit_id->clear();
    ui->lineEdit_password->clear();
}
void stu_Login_Info::on_pushButton_back_clicked() {
    this->hide();
}
