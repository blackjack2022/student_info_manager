//
// Created by black on 2023/3/21.
//

#ifndef STUDENTS_INFO_MANAGEMENT_PERSON_SCORE_INFO_H
#define STUDENTS_INFO_MANAGEMENT_PERSON_SCORE_INFO_H

#include <QWidget>
#include <QListView>
#include <QStringListModel>
#include <QSqlQuery>
#include "config.h"
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui {
    class person_score_info;
}
QT_END_NAMESPACE

class person_score_info : public QWidget {
    Q_OBJECT
public:
    explicit person_score_info(QWidget *parent = nullptr);
    ~person_score_info() override;
public:
    QStringListModel* listModel;
private:
    Ui::person_score_info *ui;
};


#endif//STUDENTS_INFO_MANAGEMENT_PERSON_SCORE_INFO_H
