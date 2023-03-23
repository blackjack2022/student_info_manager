//
// Created by black on 2023/3/20.
//

#ifndef STUDENTS_INFO_MANAGEMENT_MYQSQLTABLEMODEL_H
#define STUDENTS_INFO_MANAGEMENT_MYQSQLTABLEMODEL_H
#include <QSqlTableModel>

class MyQSqlTableModel: public QSqlTableModel{
public:
    QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
};


#endif//STUDENTS_INFO_MANAGEMENT_MYQSQLTABLEMODEL_H
