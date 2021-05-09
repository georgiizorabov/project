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



class todolist : public QMainWindow
{
    Q_OBJECT
public:
    todolist();
    ToDo_Json j;
protected slots:
    void onAdd();
    void onRemove();
    std::string change_json(QStringList &v, bool is_completed);

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
