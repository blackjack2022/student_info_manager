//
// Created by black on 2023/3/20.
//

#ifndef STUDENTS_INFO_MANAGEMENT_COURSE_INFO_MANAGE_H
#define STUDENTS_INFO_MANAGEMENT_COURSE_INFO_MANAGE_H

#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "../config.h"
#include <QSqlQueryModel>


QT_BEGIN_NAMESPACE
namespace Ui {
    class course_info_manage;
}
QT_END_NAMESPACE

class course_info_manage : public QWidget {
    Q_OBJECT

public:
    explicit course_info_manage(QWidget *parent = nullptr);
    ~course_info_manage() override;
public:
    QString input_course;
    QString exec;
    QString pre_exec;
    QString input_teacher;
    QString input_credit;
    QSqlQuery que;
public slots:
    void on_pushButton_add_cou_clicked();
    void on_pushButton_delete_cou_clicked();
    void on_pushButton_update_cou_clicked();
    void on_pushButton_check_cou_clicked();
    void on_pushButton_reset_cou_clicked();
    void on_pushButton_back_cou_clicked();
private:
    Ui::course_info_manage *ui;
};


#endif//STUDENTS_INFO_MANAGEMENT_COURSE_INFO_MANAGE_H
