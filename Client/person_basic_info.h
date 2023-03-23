//
// Created by black on 2023/3/21.
//

#ifndef STUDENTS_INFO_MANAGEMENT_PERSON_BASIC_INFO_H
#define STUDENTS_INFO_MANAGEMENT_PERSON_BASIC_INFO_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui {
    class person_basic_info;
}
QT_END_NAMESPACE

class person_basic_info : public QWidget {
    Q_OBJECT

public:
    explicit person_basic_info(QWidget *parent = nullptr);
    ~person_basic_info() override;
private:
    Ui::person_basic_info *ui;
};


#endif//STUDENTS_INFO_MANAGEMENT_PERSON_BASIC_INFO_H
