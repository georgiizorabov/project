#include "mainwindow.h"
//#include "server.h"
#include <QApplication>
#include <iostream>
#include <qpushbutton.h>
#include <qapplication.h>
#include <string>
#include <nlohmann/json.hpp>

#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include "mainwindow.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    todolist app;


    QPushButton quit("aaa");
         quit.resize(75, 30);
         quit.setFont(QFont("Times", 18, QFont::Bold));
    QLineEdit insert;
    insert.show();
         QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

         quit.show();

    app.show();
    return a.exec();
}
