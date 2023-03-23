//
// Created by black on 2023/3/17.
//

#ifndef STUDENTS_INFO_MANAGEMENT_STU_BASIC_INFO_MANAGE_H
#define STUDENTS_INFO_MANAGEMENT_STU_BASIC_INFO_MANAGE_H

#include "../config.h"
//#include "server.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QWidget>
#include "view_all_stu_info.h"
QT_BEGIN_NAMESPACE
namespace Ui {
    class stu_basic_info_manage;
}
QT_END_NAMESPACE

class stu_basic_info_manage : public QWidget {
    Q_OBJECT

public:
    explicit stu_basic_info_manage(QWidget *parent = nullptr);
    ~stu_basic_info_manage() override;

public:
//    server *back_Server;
    QString input_stu_id;
    QString input_name;
    QString input_major;
    QString sql_exec;
    QString pre_exec;
    view_all_stu_info* viewAllStuInfo;
public slots:
    void on_pushButton_upgrade_clicked();
    void on_pushButton_add_clicked();
    void on_pushButton_back_clicked();
    void on_pushButton_list_all_clicked();
    void on_pushButton_check_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_reset_clicked();
private:
    Ui::stu_basic_info_manage *ui;
};


#endif//STUDENTS_INFO_MANAGEMENT_STU_BASIC_INFO_MANAGE_H
