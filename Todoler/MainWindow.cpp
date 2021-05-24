#include "MainWindow.h"
#include "MessageList.h"
#include <QBoxLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QDateTime>
#include <QToolBar>
#include <QLabel>
#include <QDebug>
#include <QListView>
#include <QToolBar>
#include <QFuture>
#include <qlistview.h>
#include <QtConcurrent/QtConcurrent>
#include <QPushButton>
#include <QBoxLayout>
#include <iostream>
#include <QInputDialog>

QString MainWindow::get_username() const {
    return username;
}

void forEach(QAbstractItemModel* model, QModelIndex parent = QModelIndex()) {
    for(int r = 0; r < model->rowCount(parent); ++r) {
        QModelIndex index = model->index(r, 0, parent);
        QVariant name = model->data(index);
        qDebug() << name.toString() << '\t';
        qDebug() << model->data(index).toDate() << '\n';
    }
}

void MainWindow::set_username() {
        QString text = QInputDialog::getText(this, tr("Input your username"),
                                             tr("User name:"), QLineEdit::Normal);
        if (!text.isEmpty()){
            username = text;
//            j.j = json::parse(get_from_server(login.toStdString()));
//            qDebug() << j.to_str_json().c_str();
//            to_list();
        }
}

MainWindow::MainWindow(QWidget *parent) :
	QWidget(parent)
{
    QToolBar* pToolBar = new QToolBar(this);
	auto *layoutMain = new QVBoxLayout(this);
	auto *groupAdd = new QGroupBox(tr("Add message"), this);
	auto *layoutToolbar = new QHBoxLayout(groupAdd);
	auto *messageList = new MessageList(this);
    auto *CompletedList = new MessageList(this);
	auto *cmbType = new QComboBox(this);
	auto *editMessage = new QLineEdit(this);
	auto *btnPost = new QPushButton(tr("Post"), this);
    auto *btnDeletePending = new QPushButton(tr("Delete Pending"), this);
    auto *btnDeleteComleted = new QPushButton(tr("Delete All Comleted"), this);

    get_login = new QAction(this);
    get_login->setIcon(QIcon(":/pix/images/icons/login.png"));
    connect(get_login, &QAction::triggered, this, &MainWindow::set_username);
    pToolBar->addAction(get_login);
    cmbType->addItem(QIcon(QPixmap(":/pix/images/icons/information.png")),
                     "!!!");
    cmbType->addItem(QIcon(QPixmap(":/pix/images/icons/warning.png")),
                     "Calm mode");
	editMessage->setPlaceholderText(tr("Enter message here..."));

    //layoutToolbar->addWidget(pToolBar);
	layoutToolbar->addWidget(cmbType);
	layoutToolbar->addWidget(editMessage);
	layoutToolbar->addWidget(btnPost);

    qDebug("Row 1 selected");

    messageList->addMessage(tr("This is some text of an info message"),
							QPixmap(":/pix/images/icons/48/information.png"),
							QDateTime::currentDateTime());
	messageList->addMessage(tr("This is some text of a warning message"),
							QPixmap(":/pix/images/icons/48/warning.png"),
							QDateTime::currentDateTime());
	messageList->addMessage(tr("This is some text of an error message"),
							QPixmap(":/pix/images/icons/48/error.png"),
							QDateTime::currentDateTime());
    CompletedList->addMessage(tr("This is some text of an info message"),
                            QPixmap(":/pix/images/icons/48/information.png"),
                            QDateTime::currentDateTime());
    CompletedList->addMessage(tr("This is some text of a warning message"),
                            QPixmap(":/pix/images/icons/48/warning.png"),
                            QDateTime::currentDateTime());
    CompletedList->addMessage(tr("This is some text of an error message"),
                            QPixmap(":/pix/images/icons/48/error.png"),
                            QDateTime::currentDateTime());
    //pToolBar->addAction(btnDeletePending);
    layoutMain->addWidget(pToolBar);
	layoutMain->addWidget(groupAdd);
	layoutMain->addWidget(messageList);
    layoutMain->addWidget(btnDeletePending);
    layoutMain->addWidget(CompletedList);
    layoutMain->addWidget(btnDeleteComleted);

    forEach(messageList->model());

	resize(640, 480);

	connect(btnPost, &QPushButton::clicked, [messageList, cmbType,
			editMessage](){
		messageList->addMessage(editMessage->text(),
								cmbType->itemIcon(cmbType->currentIndex())
								.pixmap(48, 48),
								QDateTime::currentDateTime());
	});

    connect(btnDeletePending, &QPushButton::clicked, messageList,
            &MessageList::clear_on_index);
    connect(btnDeleteComleted, &QPushButton::clicked, CompletedList,
            &MessageList::clearAll);
}
