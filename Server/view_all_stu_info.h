//
// Created by black on 2023/3/17.
//

#ifndef STUDENTS_INFO_MANAGEMENT_VIEW_ALL_STU_INFO_H
#define STUDENTS_INFO_MANAGEMENT_VIEW_ALL_STU_INFO_H

#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "../config.h"
#include <QSqlQueryModel>
#include <QTableView>
QT_BEGIN_NAMESPACE
namespace Ui {
    class view_all_stu_info;
}
QT_END_NAMESPACE

class view_all_stu_info : public QWidget {
    Q_OBJECT

public:
    explicit view_all_stu_info(QWidget *parent = nullptr);
    ~view_all_stu_info() override;
public:
    QSqlQueryModel* sql_model;
private:
    Ui::view_all_stu_info *ui;
};


#endif//STUDENTS_INFO_MANAGEMENT_VIEW_ALL_STU_INFO_H
