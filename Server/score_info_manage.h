//
// Created by black on 2023/3/20.
//

#ifndef STUDENTS_INFO_MANAGEMENT_SCORE_INFO_MANAGE_H
#define STUDENTS_INFO_MANAGEMENT_SCORE_INFO_MANAGE_H

#include "../config.h"
#include <QDebug>
#include <QMessageBox>
#include <QModelIndexList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui {
    class score_info_manage;
}
QT_END_NAMESPACE

class score_info_manage : public QWidget {
    Q_OBJECT

public:
    explicit score_info_manage(QWidget *parent = nullptr);
    ~score_info_manage() override;

public:
    QSqlTableModel *qSqlTableModel;
    QSqlTableModel *qSqlTableModel_filter;
    QString my_filter;
public slots:
    void on_pushButton_add_sco_clicked();
    void on_pushButton_delete_sco_clicked();
    void on_pushButton_check_sco_clicked();
    void on_pushButton_cancel_search_clicked();
    void on_pushButton_back_clicked();

private:
    Ui::score_info_manage *ui;
};
#endif//STUDENTS_INFO_MANAGEMENT_SCORE_INFO_MANAGE_H
