//
// Created by black on 2023/3/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_person_course_info.h" resolved

#include "person_course_info.h"
#include "ui_person_course_info.h"


person_course_info::person_course_info(QWidget *parent) : QWidget(parent), ui(new Ui::person_course_info) {
    ui->setupUi(this);
    if(db->open()){
        qDebug()<<"connected";
    }else{
        qDebug()<<"fail to connect";
    }
    mod=new QSqlTableModel(this,*db);
    mod->setTable("course");
    ui->tableView->setModel(mod);
    ui->tableView->setEditTriggers(QTableView::NoEditTriggers);
//    ui->tableView->resizeColumnsToContents();//自动调整列宽
    for(int i=0;i<mod->columnCount();i++){
        ui->tableView->setColumnWidth(i,70);
    }
    ui->tableView->resizeRowsToContents();//自动调整行距
    mod->select();
}

person_course_info::~person_course_info() {
    delete ui;
    delete mod;
}
