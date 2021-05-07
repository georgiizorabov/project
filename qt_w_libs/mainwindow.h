#ifndef TODOLIST_H
#define TODOLIST_H

#include <QMainWindow>
#include <QListView>
#include <QStringListModel>
#include <QString>
#include <QVector>
#include <unordered_map>


class my_data{
public:
    QVector<QString> todo;
    QVector<QString> completed;
};


class todolist : public QMainWindow
{
    Q_OBJECT
public:
    todolist();
    todolist(my_data data);
    my_data data_;
protected slots:
    void onAdd();
    void onRemove();

private:


    QListView* m_pwPending = nullptr;
    QListView* m_pwCompleted = nullptr;

    QAction* m_pActAdd = nullptr;
    QAction* m_pActRemove = nullptr;


    //Qstring login;
            size_t added = 0;
            size_t edited = 0;
};



#endif // TODOLIST_H
