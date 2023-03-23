//
// Created by black on 2023/3/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_score_info_manage.h" resolved

#include "score_info_manage.h"
#include "ui_score_info_manage.h"

score_info_manage::score_info_manage(QWidget *parent) : QWidget(parent), ui(new Ui::score_info_manage) {
    if (db->open()) {
        qDebug() << "connected";
    } else {
        qDebug() << "fail to connect";
    }
    ui->setupUi(this);
    qSqlTableModel = new QSqlTableModel(this, *db);
    qSqlTableModel_filter = new QSqlTableModel(this, *db);
    qSqlTableModel->setTable("score");
    qSqlTableModel_filter->setTable("score");
    ui->tableView->setModel(qSqlTableModel); //设置主module
    ui->tableView->resizeColumnsToContents();//自动调整列宽
    ui->tableView->setColumnWidth(0, 60);
    ui->tableView->resizeRowsToContents();//自动调整行距
    ui->tableView->setEditTriggers(QTableView::DoubleClicked);
    qSqlTableModel->select();
}
score_info_manage::~score_info_manage() {
    delete ui;
    delete qSqlTableModel;
    delete qSqlTableModel_filter;
}

void score_info_manage::on_pushButton_add_sco_clicked() {
    ui->tableView->setModel(qSqlTableModel);//设置主module
    while (qSqlTableModel->canFetchMore()) {
        qSqlTableModel->fetchMore();
    }
    int raw_num = qSqlTableModel->rowCount();
    if (qSqlTableModel->insertRow(raw_num)) {
        qDebug() << "insert succeed";
    }
    qSqlTableModel->setData(qSqlTableModel->index(raw_num, 0), "");
    ui->tableView->scrollToBottom();
    //qSqlTableModel->select();//在自动同步数据的模式下，插入数据时尽量不调用此函数，可能会导致修改提交到数据库失败
}
void score_info_manage::on_pushButton_delete_sco_clicked() {
    ui->tableView->setModel(qSqlTableModel);//设置主module
    QModelIndexList lst = ui->tableView->selectionModel()->selectedIndexes();
    for (auto &x: lst) {
        qSqlTableModel->removeRow(x.row());
    }
    if (!lst.empty()) {
        QMessageBox::information(this, "提示", "删除成功！");
    } else {
        QMessageBox::warning(this, "警告", "未选中需要删除的行!");
    }
    qSqlTableModel->select();
}
void score_info_manage::on_pushButton_check_sco_clicked() {
    my_filter = QString("stu_id='%1'").arg(ui->lineEdit->text().toInt());
    ui->tableView->setModel(qSqlTableModel_filter);
    qSqlTableModel_filter->setFilter(my_filter);
    qSqlTableModel_filter->select();
}
void score_info_manage::on_pushButton_cancel_search_clicked() {
    ui->lineEdit->clear();
    ui->tableView->setModel(qSqlTableModel);//设置主module
    qSqlTableModel->select();
}
void score_info_manage::on_pushButton_back_clicked() {
    this->hide();
}
