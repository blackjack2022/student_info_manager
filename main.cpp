#include <QApplication>
#include <QPushButton>
#include <QTextCodec>
#include "mainwindow/mainwindow.h"
#include "config.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    db=new QSqlDatabase;
    if(QSqlDatabase::contains("qt_sql_default_connection")){
        *db=QSqlDatabase::database("qt_sql_default_connection");
    }else{
        *db=QSqlDatabase::addDatabase(database_driver);
        db->setDatabaseName(database_name);
        db->setHostName(host_name);
        db->setUserName(user_name);
        db->setPassword(database_password);
    }
    if(db->open()){
        qDebug()<<"connected";
    }else{
        qDebug()<<"fail to connect database";
    }
    qDebug()<<"main";
    Mainwindow M;
    M.show();


    return QApplication::exec();
}
