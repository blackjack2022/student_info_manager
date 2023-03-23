//
// Created by black on 2023/3/18.
//

#ifndef STUDENTS_INFO_MANAGEMENT_STU_LOGIN_INFO_H
#define STUDENTS_INFO_MANAGEMENT_STU_LOGIN_INFO_H

#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "../config.h"
#include <QSqlQueryModel>


QT_BEGIN_NAMESPACE
namespace Ui {
    class stu_Login_Info;
}
QT_END_NAMESPACE

class stu_Login_Info : public QWidget {
    Q_OBJECT
public:
    QString input_id;
    QString input_password;
    QString exec;
    QString pre_exec;
    QSqlQuery que;
public:
    explicit stu_Login_Info(QWidget *parent = nullptr);
    ~stu_Login_Info() override;
public slots:
    void on_pushButton_checked_clicked();
    void on_pushButton_add_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_upgrade_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_back_clicked();

private:
    Ui::stu_Login_Info *ui;
};


#endif//STUDENTS_INFO_MANAGEMENT_STU_LOGIN_INFO_H
