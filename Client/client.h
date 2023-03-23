//
// Created by black on 2023/3/16.
//

#ifndef STUDENTS_INFO_MANAGEMENT_CLIENT_H
#define STUDENTS_INFO_MANAGEMENT_CLIENT_H

#include <QWidget>
#include "person_basic_info.h"
#include "person_course_info.h"
#include "person_score_info.h"
QT_BEGIN_NAMESPACE
namespace Ui {
    class client;
}
QT_END_NAMESPACE

class client : public QWidget {
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client() override;
public:
    person_basic_info* personBasicInfo;
    person_course_info* personCourseInfo;
    person_score_info* personScoreInfo;
public slots:
    void on_pushButton_basic_client_clicked();
    void on_pushButton_course_client_clicked();
    void on_pushButton_score_client_clicked();
    void on_pushButton_back_client_clicked();
private:
    Ui::client *ui;
};


#endif//STUDENTS_INFO_MANAGEMENT_CLIENT_H
