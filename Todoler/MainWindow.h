#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "json.h"

class MainWindow : public QWidget
{
	Q_OBJECT
private:
    QString username;
    QString email;
public:
    ToDo_Json j;
    QString get_username() const;
    void set_username(/*MessageList *ml,  MessageList* cl*/);
    void to_list(/*MessageList *ml,  MessageList* cl*/);
    QAction *get_login = nullptr;
	explicit MainWindow(QWidget *parent = nullptr);
};

#endif // MAINWINDOW_H

