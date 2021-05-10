#ifndef TODOLIST_H
#define TODOLIST_H

#include <QMainWindow>
#include <QListView>
#include "json.h"
#include <QStringListModel>
#include <string>
#include <QString>
#include <QVector>
#include <unordered_map>
#include <QString>


class todolist : public QMainWindow
{
    Q_OBJECT
public:
    todolist();
    ToDo_Json j;
    void change_json(QStringList v, bool is_completed);
protected slots:
    void onAdd();
    void onRemove();
    void onLogin();
    void to_list();


private:

    QListView* m_pwPending = nullptr;
    QListView* m_pwCompleted = nullptr;

    QAction* m_pActAdd = nullptr;
    QAction* m_pActLogin = nullptr;
    QAction* m_pActRemove = nullptr;


    QString login;
            size_t added = 0;
            size_t edited = 0;
};



#endif // TODOLIST_H
