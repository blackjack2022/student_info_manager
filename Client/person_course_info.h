//
// Created by black on 2023/3/21.
//

#ifndef STUDENTS_INFO_MANAGEMENT_PERSON_COURSE_INFO_H
#define STUDENTS_INFO_MANAGEMENT_PERSON_COURSE_INFO_H

#include <QWidget>
#include <QSqlTableModel>
#include <QDebug>
#include <QTableView>
#include "config.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class person_course_info;
}
QT_END_NAMESPACE

class person_course_info : public QWidget {
    Q_OBJECT
public:
    explicit person_course_info(QWidget *parent = nullptr);
    ~person_course_info() override;
public:
    QSqlTableModel* mod;
private:
    Ui::person_course_info *ui;
};


#endif//STUDENTS_INFO_MANAGEMENT_PERSON_COURSE_INFO_H
