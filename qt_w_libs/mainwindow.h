#ifndef TODOLIST_H
#define TODOLIST_H

#include <QMainWindow>
#include <QListView>
#include <QStringListModel>
#include <QString>
#include <vector>
#include <unordered_map>
class todolist : public QMainWindow
{
    Q_OBJECT
public:
    todolist();
protected slots:
    void onAdd();
    void onRemove();
    void onEdit();

private:
    QListView* m_pwPending = nullptr;
    QListView* m_pwCompleted = nullptr;

    QAction* m_pActAdd = nullptr;
    QAction* m_pActRemove = nullptr;
    QAction* m_pActEdit = nullptr;

            std::vector<std::pair<QString, bool>> todos;
            std::unordered_map<QString, size_t> todos1;
    //Qstring login;
            size_t added = 0;
            size_t edited = 0;




};


#endif // TODOLIST_H
