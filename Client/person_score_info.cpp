//
// Created by black on 2023/3/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_person_score_info.h" resolved

#include "person_score_info.h"
#include "ui_person_score_info.h"

person_score_info::person_score_info(QWidget *parent) : QWidget(parent), ui(new Ui::person_score_info) {
    ui->setupUi(this);
    if(db->open()){
        qDebug()<<"connected";
    }else{
        qDebug()<<"fail to connect";
    }
    QSqlQuery que;
    qDebug()<<client_stu_id;
    QString exec=QString("SELECT 高数,大学物理,C语言程序设计基础,time FROM score WHERE stu_id='%1'").arg(client_stu_id);
    if(que.exec(exec)){
        qDebug()<<"执行成功";
        qDebug()<<que.size();
    }else{
        qDebug()<<"执行失败";
    }
    QStringList lst;
    que.next();
    lst.append(QString("高数：")+que.value(0).toString());
    lst.append(QString("大学物理：")+que.value(1).toString());
    lst.append(QString("C语言程序设计基础：")+que.value(2).toString());
    lst.append(QString("time：")+que.value(3).toString());
    listModel=new QStringListModel(lst);
    ui->listView->setModel(listModel);
}

person_score_info::~person_score_info() {
    delete ui;
    if(listModel){
        delete listModel;
        listModel=nullptr;
    }
}
