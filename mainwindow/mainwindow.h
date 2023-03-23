//
// Created by black on 2023/3/15.
//

#ifndef STUDENTS_INFO_MANAGEMENT_MAINWINDOW_H
#define STUDENTS_INFO_MANAGEMENT_MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "../config.h"
#include <QDebug>
#include "../Server/server.h"
#include "../Client/client.h"
#include <QSqlQuery>
#include <QMessageBox>
extern QString client_stu_id;
QT_BEGIN_NAMESPACE
namespace Ui {
    class Mainwindow;
}
QT_END_NAMESPACE

class Mainwindow : public QMainWindow {
    Q_OBJECT
private:
    server* to_Server;
    client* to_Client;
public:
    explicit Mainwindow(QWidget *parent = nullptr);
    ~Mainwindow() override;
public slots:
    void on_pushButton_login_clicked();
    void on_pushButton_reset_clicked();
private:
    Ui::Mainwindow *ui;
};


#endif//STUDENTS_INFO_MANAGEMENT_MAINWINDOW_H
