//
// Created by black on 2023/3/17.
//

// You may need to build the project (run Qt uic code generator) to get "ui_stu_basic_info_manage.h" resolved

#include "stu_basic_info_manage.h"
#include "ui_stu_basic_info_manage.h"


stu_basic_info_manage::stu_basic_info_manage(QWidget *parent) : QWidget(parent), ui(new Ui::stu_basic_info_manage) {
    ui->setupUi(this);
    viewAllStuInfo=new view_all_stu_info;
}

stu_basic_info_manage::~stu_basic_info_manage() {
    delete ui;
    delete viewAllStuInfo;
}
void stu_basic_info_manage::on_pushButton_upgrade_clicked() {
    if(db->open()){
        qDebug()<<"connected";
    }else{
        qDebug()<<"fail to connect";
    }
    QSqlQuery que;
    input_stu_id=ui->lineEdit_id->text();
    input_name=  ui->lineEdit_name->text();
    input_major= ui->lineEdit_major->text();
    pre_exec=QString("select name from my_class where stu_id='%1'").arg(input_stu_id);
    if(que.exec(pre_exec)&&que.size()>0){
        que.clear();
        sql_exec=QString("update my_class set name ='%1',major ='%2' where stu_id = '%3'").arg(input_name).arg(input_major).arg(input_stu_id);
        qDebug()<<sql_exec;
        if(que.exec(sql_exec)){
            QMessageBox::information(nullptr,"提示","修改成功！",QMessageBox::Yes);
        }else{
            QMessageBox::warning(nullptr,"警告","修改失败！",QMessageBox::Yes);
        }
    }else{
        QMessageBox::warning(this,"警告","学号输入错误！");
    }

}
void stu_basic_info_manage::on_pushButton_add_clicked() {
    if(db->open()){
        qDebug()<<"connected";
    }else{
        qDebug()<<"fail to connect";
    }
    QSqlQuery que;
    input_name=ui->lineEdit_name->text();
    input_stu_id=ui->lineEdit_id->text();
    input_major=ui->lineEdit_major->text();
//    sql_exec="insert into my_class(stu_id,name,major) values('"+input_stu_id+"','"+input_name+"','"+input_major+"')";//纯SQL语句添加数据
    sql_exec="insert into my_class(stu_id,name,major) values(?,?,?)";
    que.prepare(sql_exec);//对SQL语句进行预处理，避免SQL注入问题
    que.addBindValue(input_stu_id);
    que.addBindValue(input_name);
    que.addBindValue(input_major);
    qDebug()<<sql_exec;
    if(que.exec()){
        QMessageBox::information(nullptr,"提示","添加成功！",QMessageBox::Yes);
    }else{
        QMessageBox::warning(nullptr,"警告","添加失败！",QMessageBox::Yes);
    }
}
void stu_basic_info_manage::on_pushButton_back_clicked() {
    this->hide();
//    back_Server->show();
}
void stu_basic_info_manage::on_pushButton_list_all_clicked() {
//    input_name="str";
//    this->hide();
    viewAllStuInfo->show();
}
void stu_basic_info_manage::on_pushButton_check_clicked() {
    if(db->open()){
        qDebug()<<"connected";
    }else{
        qDebug()<<"fail to connect";
    }
    input_name=ui->lineEdit_id->text();
    QSqlQuery que;
    sql_exec=QString("select stu_id,name,major from my_class where stu_id = '%1'").arg(input_name);
    qDebug()<<sql_exec;
    if(que.exec(sql_exec)&&que.size()){
        que.next();//跳转到下一个记录，注意：执行完sql语句后的默认记录是无效的，必须使用此函数跳转到第一个有效的记录
        ui->lineEdit_name->insert(que.value(1).toString());//value(对应域的下标)返回当前记录中对应下标的值
        ui->lineEdit_major->insert(que.value(2).toString());
    }else{
        qDebug()<<que.size();
        QMessageBox::warning(nullptr,"警告","学号输入错误！",QMessageBox::Yes);
    }
}
void stu_basic_info_manage::on_pushButton_delete_clicked() {
    if(db->open()){
        qDebug()<<"connected";
    }else{
        qDebug()<<"fail to connect";
    }
    input_stu_id=ui->lineEdit_id->text();
    QSqlQuery que;
    pre_exec=QString("select name from my_class where stu_id='%1'").arg(input_stu_id);
    if(que.exec(pre_exec)&&que.size()>0){
        que.clear();
        sql_exec=QString("delete from my_class where stu_id= '%1'").arg(input_stu_id);
        if(que.exec(sql_exec)){
            QMessageBox::information(this,"提示","删除成功！");
        }else{
            QMessageBox::critical(this,"错误","删除失败！");
        }
    }else{
        QMessageBox::warning(this,"警告","学号输入错误！");
    }

}
void stu_basic_info_manage::on_pushButton_reset_clicked() {
    ui->lineEdit_name->clear();
    ui->lineEdit_major->clear();
    ui->lineEdit_id->clear();
}
