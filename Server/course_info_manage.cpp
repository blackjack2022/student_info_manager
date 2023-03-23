//
// Created by black on 2023/3/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_course_info_manage.h" resolved

#include "course_info_manage.h"
#include "ui_course_info_manage.h"


course_info_manage::course_info_manage(QWidget *parent) : QWidget(parent), ui(new Ui::course_info_manage) {
    ui->setupUi(this);
}

course_info_manage::~course_info_manage() {
    delete ui;
}
void course_info_manage::on_pushButton_add_cou_clicked() {
    if(db->open()){
        qDebug()<<"connected";
    }else{
        qDebug()<<"fail to connect";
    }
    input_course=ui->lineEdit_course->text();
    input_credit=ui->lineEdit_credit->text();
    input_teacher=ui->lineEdit_teacher->text();
    que.clear();
    exec = QString("insert into course(course,teacher,credit) values('%1','%2','%3')").arg(input_course).arg(input_teacher).arg(input_credit);
    qDebug() << exec;
    if (que.exec(exec)) {
        QMessageBox::information(this, "提示", "添加成功！");
    } else {
        QMessageBox::critical(this, "错误", "添加失败！");
    }
}
void course_info_manage::on_pushButton_delete_cou_clicked() {
    if(db->open()){
        qDebug()<<"connected";
    }else{
        qDebug()<<"fail to connect";
    }
    input_course=ui->lineEdit_course->text();
    pre_exec = QString("select course from course where course='%1'").arg(input_course);
    if (que.exec(pre_exec) && que.size() > 0) {
        exec = QString("delete from course where course= '%1'").arg(input_course);
        if (que.exec(exec)) {
            QMessageBox::information(this, "提示", "删除成功！");
        } else {
            QMessageBox::critical(this, "错误", "删除失败！");
        }
    }else {
        QMessageBox::warning(this, "警告", "课程名输入错误！");
    }
}
void course_info_manage::on_pushButton_update_cou_clicked() {
    if(db->open()){
        qDebug()<<"connected";
    }else{
        qDebug()<<"fail to connect";
    }
    input_course=ui->lineEdit_course->text();
    input_credit=ui->lineEdit_credit->text();
    input_teacher=ui->lineEdit_teacher->text();
    pre_exec = QString("select course from course where course='%1'").arg(input_course);
    if (que.exec(pre_exec) && que.size() > 0) {
        exec = QString("update course set teacher='%1',credit='%2' where course= '%3'").arg(input_teacher).arg(input_credit).arg(input_course);
        que.clear();
        qDebug() << exec;
        if (que.exec(exec)) {
            QMessageBox::information(this, "提示", "修改成功！");
        } else {
            QMessageBox::critical(this, "错误", "修改失败！");
        }
    }else{
        QMessageBox::warning(this, "警告", "课程名输入错误！");
    }
}
void course_info_manage::on_pushButton_check_cou_clicked() {
    if(db->open()){
        qDebug()<<"connected";
    }else{
        qDebug()<<"fail to connect";
    }
    input_course=ui->lineEdit_course->text();
    exec = QString("select course,teacher, credit from course where course= '%1' ").arg(input_course);
    que.clear();
    qDebug() << exec;
    if (que.exec(exec)&&que.size()) {
        que.next();
        ui->lineEdit_teacher->setText(que.value(1).toString());
        ui->lineEdit_credit->setText(que.value(2).toString());
    } else {
        QMessageBox::critical(this, "错误", "课程名输入错误！");
    }
}
void course_info_manage::on_pushButton_reset_cou_clicked() {
    ui->lineEdit_course->clear();
    ui->lineEdit_credit->clear();
    ui->lineEdit_teacher->clear();
}
void course_info_manage::on_pushButton_back_cou_clicked() {
    this->hide();
}
