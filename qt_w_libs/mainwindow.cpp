#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "server.h"
#include <QLabel>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QBoxLayout>
#include <iostream>



class my_model : public QStringListModel{
public:
        todolist *list;
    my_model(todolist *list_) : list(list_){}

    bool moveRows(const QModelIndex &sourceParent, int sourceRow, int count, const QModelIndex &destinationParent, int destinationChild) override{
        qDebug() << rowCount()-1 << "80085";
        if(destinationChild != rowCount()-1){
            return 0;
        }
        qDebug() << "in move rows";
        qDebug() <<sourceRow;
        qDebug() <<destinationChild;
        auto change1 = list->data_.todo[sourceRow];
        list->data_.todo.erase(list->data_.todo.begin() + sourceRow);
        list->data_.todo.push_back(change1);
        for(auto i : list->data_.todo){
            qDebug() << i;
        }
        return QStringListModel::moveRows(sourceParent, sourceRow, count, destinationParent, destinationChild);
    }
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override{
//        qDebug() << value.toString();
        list->data_.todo[index.row()] = value.toString();
        for(auto i : list->data_.todo){
            qDebug() << i;
        }
        qDebug() << "==================================";
        return QStringListModel::setData(index, value, Qt::EditRole);
    }
};

todolist::todolist(my_data data) : data_(data){
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

    m_pwPending = new QListView(this);
    m_pwPending->setDragEnabled(true);
    m_pwPending->setAcceptDrops(true);
    m_pwPending->setDropIndicatorShown(true);
    m_pwPending->setDefaultDropAction(Qt::MoveAction);
    pHLayout->addWidget(m_pwPending);

    m_pwCompleted = new QListView(this);
    m_pwCompleted->setDragEnabled(true);
    m_pwCompleted->setAcceptDrops(true);
    m_pwCompleted->setDropIndicatorShown(true);
    m_pwCompleted->setDefaultDropAction(Qt::MoveAction);
    pHLayout->addWidget(m_pwCompleted);

    m_pwPending->setModel(new my_model(this));
    m_pwCompleted->setModel(new my_model(this));

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
    data_.todo.push_back("");
}

void todolist::onRemove()
{
   QModelIndex oIndex = m_pwPending->currentIndex();
   m_pwPending->model()->removeRow(oIndex.row());

}


