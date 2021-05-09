#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "server.h"
#include "json.h"
#include <QLabel>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QBoxLayout>
#include <iostream>

void print_vec(QStringList v, bool is_completed){
    qDebug() << "==============\nis completed:\t" << is_completed << "\n";
    for(auto &i : v){
        qDebug() << i;
    }
    qDebug() << "\n";
}

//bool to_server(std::string str){

//}


//class my_QListView : public QListView{
//public:
//    void dragMoveEvent(QDragMoveEvent *e) override{
//        //qDebug() << "in drag move event";
//        QListView::dragMoveEvent(e);
//    }
//    void indexesMoved(const QModelIndexList &indexes){
//        //qDebug() << "in indexdes moved";
//        for(auto i : indexes){
//            qDebug() << i;
//        }
//        QListView::indexesMoved(indexes);
//    }
//};

class my_model : public QStringListModel{
public:
    todolist *list;
    bool is_completed;
    my_model(todolist *list_, bool ic) : list(list_), is_completed(ic){}
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override{
        qDebug() << "in insert\t" << parent.row() << '\t' << parent.column() << '\t' << count << '\t' << row;
        bool return_value =  QStringListModel::insertRows(row,count,parent);
        list->j.change(my_model::stringList(), is_completed); // вот тут написано что мы меняем в туду json
        return return_value;
    }
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override{
        qDebug() << "in remove\t" << QModelIndex().column();
        bool return_value =  QStringListModel::removeRows(row,count,parent);
        list->j.change(my_model::stringList(), is_completed); // вот тут написано что мы меняем в туду json
        return return_value;
    }
    bool moveRows(const QModelIndex &sourceParent, int sourceRow, int count, const QModelIndex &destinationParent, int destinationChild) override{
        qDebug() << "in move rows\t" << sourceRow << '\t' << destinationChild;
        print_vec(my_model::stringList(), 0);
        bool return_value =   QStringListModel::moveRows(sourceParent, sourceRow, count, destinationParent, destinationChild);
        list->j.change(my_model::stringList(), is_completed); // вот тут написано что мы меняем в туду json
        return return_value;
    }
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override{
        qDebug() << "in setdata\t" << index.column() << '\t' << index.row();
        bool return_value = QStringListModel::setData(index, value, role);
        list->j.change(my_model::stringList(), is_completed); // вот тут написано что мы меняем в туду json
        return return_value;
    }
};

todolist::todolist() {
    QWidget* pWidget = new QWidget(this);
    pWidget->setStyleSheet("background-color: #ECF0F1");
    setCentralWidget(pWidget);

    QVBoxLayout* pMainLayout = new QVBoxLayout();
    pWidget->setLayout(pMainLayout);

    QLabel* pwTitle = new QLabel("TO DO LIST", this);
    pMainLayout->addWidget(pwTitle);
    pwTitle->setAlignment(Qt::AlignCenter);
    pwTitle->setStyleSheet("font-size: 30pt; margin: 10%");

    QHBoxLayout* pHLayoutLabels = new QHBoxLayout();
    pMainLayout->addLayout(pHLayoutLabels);

    QLabel* plblPending = new QLabel("Pending", this);
    plblPending->setStyleSheet("font-size: 15pt;");
    pHLayoutLabels->addWidget(plblPending);

    QLabel* plblCompleted = new QLabel("Completed", this);
    plblCompleted->setStyleSheet("font-size: 15pt;");
    pHLayoutLabels->addWidget(plblCompleted);

    QHBoxLayout* pHLayout = new QHBoxLayout();
    pMainLayout->addLayout(pHLayout);

    m_pwPending = new QListView();//(this)
    m_pwPending->setDragEnabled(true);
    m_pwPending->setAcceptDrops(true);
    m_pwPending->setDropIndicatorShown(true);
    m_pwPending->setDefaultDropAction(Qt::MoveAction);
    pHLayout->addWidget(m_pwPending);

    m_pwCompleted = new QListView();//(this)
    m_pwCompleted->setDragEnabled(true);
    m_pwCompleted->setAcceptDrops(true);
    m_pwCompleted->setDropIndicatorShown(true);
    m_pwCompleted->setDefaultDropAction(Qt::MoveAction);
    pHLayout->addWidget(m_pwCompleted);

    m_pwPending->setModel(new my_model(this, false));
    m_pwCompleted->setModel(new my_model(this, true));

    m_pwPending->setStyleSheet
    ("QListView { font-size: 20pt; font-weight: bold; }"
     "QListView::item { background-color: #E74C3C; padding: 10%;"
     "border: 1px solid #C0392B; }"
     "QListView::item::hover { background-color: #C0392B }");

    m_pwCompleted->setStyleSheet
    ("QListView { font-size: 20pt; font-weight: bold; }"
     "QListView::item { background-color: #2ECC71; padding: 10%;"
     "border: 1px solid #27AE60; }"
     "QListView::item::hover { background-color: #27AE60 }");

    QToolBar* pToolBar = new QToolBar(this);
    addToolBar(pToolBar);

    m_pActAdd = new QAction(this);
    m_pActAdd->setIcon(QIcon(":/icons/images/add.png"));
    connect(m_pActAdd, &QAction::triggered, this, &todolist::onAdd);

    m_pActRemove = new QAction(this);
    m_pActRemove->setIcon(QIcon(":/icons/images/delete.png"));
    connect(m_pActRemove, &QAction::triggered, this, &todolist::onRemove);



    pToolBar->addAction(m_pActAdd);
    pToolBar->addAction(m_pActRemove);


}




void todolist::onAdd()
{
    m_pwPending->model()->insertRow(m_pwPending->model()->rowCount());
    QModelIndex oIndex = m_pwPending->model()->index(
                m_pwPending->model()->rowCount() - 1, 0);
}

std::string todolist::change_json(QStringList &v, bool is_completed){
    j.change(v, is_completed);
    return j.to_str_json();
}

void todolist::onRemove()
{
   QModelIndex oIndex = m_pwPending->currentIndex();
   m_pwPending->model()->removeRow(oIndex.row());

}


