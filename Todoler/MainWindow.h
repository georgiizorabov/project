#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "MessageList.h"

class MainWindow : public QWidget
{
	Q_OBJECT
private:
    QString username;
public:
    QString get_username() const;
    void set_username();
    QAction *get_login = nullptr;
	explicit MainWindow(QWidget *parent = nullptr);
};

#endif // MAINWINDOW_H

