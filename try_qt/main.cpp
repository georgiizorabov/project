#include "todolist.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    todolist app;
    app.show();

    return a.exec();
}
