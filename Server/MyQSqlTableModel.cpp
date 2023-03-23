//
// Created by black on 2023/3/20.
//

#include "MyQSqlTableModel.h"
#include <QDebug>
QVariant QSqlTableModel::data(const QModelIndex &idx, int role) const {
    if(!idx.isValid()){
        qDebug()<<"join1";
        return QVariant();
    }
    if(role==Qt::TextAlignmentRole){
        qDebug()<<"join2";
        return Qt::AlignCenter;
    }
    qDebug()<<"join3";
    return QVariant();
}