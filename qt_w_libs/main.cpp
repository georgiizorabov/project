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

    app.show();
    return a.exec();
}
