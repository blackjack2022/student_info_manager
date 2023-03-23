//
// Created by black on 2023/3/16.
//

#ifndef STUDENTS_INFO_MANAGEMENT_SERVER_H
#define STUDENTS_INFO_MANAGEMENT_SERVER_H

#include <QWidget>
#include "stu_basic_info_manage.h"
#include "stu_Login_Info.h"
#include "admin_info_manage.h"
#include "course_info_manage.h"
#include "score_info_manage.h"
#include "config.h"
QT_BEGIN_NAMESPACE
namespace Ui {
    class server;
}
QT_END_NAMESPACE

class server : public QWidget {
    Q_OBJECT

public:
    explicit server(QWidget *parent = nullptr);
    ~server() override;
public:
    stu_basic_info_manage* stuBasicInfoManage;
    stu_Login_Info* stuLoginInfo;
    admin_info_manage* adminInfoManage;
    course_info_manage* courseInfoManage;
    score_info_manage* scoreInfoManage;
public slots:
    void on_pushButton_basic_info_clicked();
    void on_pushButton_course_clicked();
    void on_pushButton_login_info_clicked();
    void on_pushButton_score_info_clicked();
    void on_pushButton_manager_info_clicked();
    void on_pushButton_back_clicked();
private:
    Ui::server *ui;
};


#endif//STUDENTS_INFO_MANAGEMENT_SERVER_H
