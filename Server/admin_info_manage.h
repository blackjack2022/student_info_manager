//
// Created by black on 2023/3/19.
//

#ifndef STUDENTS_INFO_MANAGEMENT_ADMIN_INFO_MANAGE_H
#define STUDENTS_INFO_MANAGEMENT_ADMIN_INFO_MANAGE_H

#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "../config.h"
#include <QSqlQueryModel>


QT_BEGIN_NAMESPACE
namespace Ui {
    class admin_info_manage;
}
QT_END_NAMESPACE

class admin_info_manage : public QWidget {
    Q_OBJECT

public:
    explicit admin_info_manage(QWidget *parent = nullptr);
    ~admin_info_manage() override;
public:
    QString input_id;
    QString input_password;
    QString exec;
    QString pre_exec;
    QSqlQuery que;
public slots:
    void on_pushButton_add_admin_clicked();
    void on_pushButton_delete_admin_clicked();
    void on_pushButton_update_admin_clicked();
    void on_pushButton_check_admin_clicked();
    void on_pushButton_clear_admin_clicked();
    void on_pushButton_back_admin_clicked();
private:
    Ui::admin_info_manage *ui;
};


#endif//STUDENTS_INFO_MANAGEMENT_ADMIN_INFO_MANAGE_H
