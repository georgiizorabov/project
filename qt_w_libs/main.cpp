#include "mainwindow.h"
#include <cpr/cpr.h>
#include <QApplication>
#include <iostream>
#include <qpushbutton.h>
#include <qapplication.h>
#include <string>
#include <nlohmann/json.hpp>

#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
//    cpr
    cpr::Response r = cpr::Get(cpr::Url{"http://neverssl.com/"});


    QString str = QString::fromUtf8(r.text.c_str());
    QPushButton hello(str);
    hello.resize(100, 30);

    hello.show();
//    cpr
    using json = nlohmann::json;

    json j;
    j["id"] = 5;

    return app.exec();
}
