//
// Created by black on 2023/3/17.
//

// You may need to build the project (run Qt uic code generator) to get "ui_view_all_stu_info.h" resolved

#include "view_all_stu_info.h"
#include "ui_view_all_stu_info.h"


view_all_stu_info::view_all_stu_info(QWidget *parent) : QWidget(parent), ui(new Ui::view_all_stu_info) {
    ui->setupUi(this);
    if(db->open()){
        qDebug()<<"connected";
    }else{
        qDebug()<<"fail to connect";
    }
    sql_model=new QSqlQueryModel(ui->tableView);
    sql_model->setQuery("select * from my_class",*db);
    sql_model->setHeaderData(0,Qt::Horizontal,QObject::tr("专业"));
    sql_model->setHeaderData(1,Qt::Horizontal,QObject::tr("学号"));
    sql_model->setHeaderData(2,Qt::Horizontal,QObject::tr("姓名"));
    ui->tableView->setModel(sql_model);
//    db.close();
}

view_all_stu_info::~view_all_stu_info() {
    delete ui;
    delete sql_model;
}
