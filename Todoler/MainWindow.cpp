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
#include <QLayout>
#include <QTextEdit>
#include <QDebug>
#include <QListView>
#include <QStandardItemModel>
#include <QToolBar>
#include <QFuture>
#include <dirent.h>
#include <stdio.h>
#include <qlistview.h>
#include <QtConcurrent/QtConcurrent>
#include <boost/filesystem.hpp>
#include <sstream>
#include <QPushButton>
#include <filesystem>
#include <string>
#include <QBoxLayout>
#include <iostream>
#include <QInputDialog>
#include "server.h"
#include <QColorDialog>
#include <cpr/cpr.h>

QString MainWindow::get_username() const {
    return username;
}

void MainWindow::set_username(MessageList *ml,  MessageList* cl) {
        QString text = QInputDialog::getText(this, tr("Input your username"),
                                             tr("User name:"), QLineEdit::Normal);
       if (!text.isEmpty()){
            username = text;
            j.j["username"] = username.toStdString();
            j.j = json::parse(get_from_server(username.toStdString())); //Передть строку из сервера
            qDebug() << "===============\n" << j.to_str_json().c_str(); // проверка
            to_list(ml, cl);
        }
       if(j.j["email"] != ""){ //check if email already exists
           return;
       }
       QString text1 = QInputDialog::getText(this, tr("Input your email"),
                                            tr("User email:"), QLineEdit::Normal);
       if (!text1.isEmpty()){
            email = text1;
            put_email_on_server(email.toStdString());
            j.j["email"] = email.toStdString();
       }

       //qDebug() << j.j.dump(4).c_str();
}

void MainWindow::to_list(MessageList *ml,  MessageList* cl) {
    static_cast<QStandardItemModel *>(ml->model())->clear();
    static_cast<QStandardItemModel *>(cl->model())->clear();
    for (auto& element : j.j["Progress"].items()) {
        std::string todo = element.value()[0].dump(4);
        std::string date = element.value()[1].dump(4);
////        qDebug() << todo.substr(1, todo.size() - 2).c_str() << "\t" << date.substr(1, date.size() - 2).c_str();
        if (date.size() <= 2) {
            ml->addMessage(tr(todo.substr(1, todo.size() - 2).c_str()),
                                QPixmap(":/pix/images/icons/information.png"),
                                QDateTime::fromString(""), 0, this, false, false);
        } else {
            ml->addMessage(tr(todo.substr(1, todo.size() - 2).c_str()),
                                    QPixmap(":/pix/images/icons/information.png"),
                                    QDateTime::fromString(date.substr(1, date.size() - 2).c_str(), "yyyy-MM-dd hh:mm"), 0, this, false, false);
        }
    }
    for (auto& element : j.j["Completed"].items()) {
        std::string todo = element.value()[0].dump(4);
        std::string date = element.value()[1].dump(4);
////        qDebug() << todo.substr(1, todo.size() - 2).c_str() << "\t" << date.substr(1, date.size() - 2).c_str();
        if (date.size() <= 2) {
            cl->addMessage(tr(todo.substr(1, todo.size() - 2).c_str()),
                                        QPixmap(":/pix/images/icons/ok.png"),
                           QDateTime::fromString(""), 1, this, false, false);
        } else {
            cl->addMessage(tr(todo.substr(1, todo.size() - 2).c_str()),
                                        QPixmap(":/pix/images/icons/ok.png"),
                                        QDateTime::fromString(date.substr(1, date.size() - 2).c_str(), "yyyy-MM-dd hh:mm"), 1, this, false, false);
        }
    }
}

void MainWindow::set_icon(QComboBox* box){
    for (boost::filesystem::recursive_directory_iterator it("../Todoler/images/icons"), end; it != end; ++it) {
           if (it->path().extension() == ".png") {
               std::stringstream ss;
               ss << *it;
               std::string str = ss.str();
               std::cout << str.substr(25, str.size() - 26) << std::endl;
               box->addItem(QIcon(QPixmap((":/pix/images/icons/" + str.substr(25, str.size() - 26)).c_str())),
                            "");
           }
      }
}

void MainWindow::read_all_icons(){
    for (boost::filesystem::recursive_directory_iterator it("../Todoler/images/icons"), end; it != end; ++it) {
           if (it->path().extension() == ".png") {
               std::stringstream ss;
               ss << *it;
               std::string str = ss.str();
               std::cout << str.substr(25, str.size() - 26) << std::endl;
           }
      }
}

MainWindow::MainWindow(QWidget *parent) :
	QWidget(parent)
{
    QToolBar* pToolBar = new QToolBar(this);
    auto *btnDeadline = new QPushButton(tr("Add deadline"), this);
	auto *layoutMain = new QVBoxLayout(this);
	auto *groupAdd = new QGroupBox(tr("Add message"), this);
	auto *layoutToolbar = new QHBoxLayout(groupAdd);
    auto *messageList = new MessageList(this);
    auto *CompletedList = new MessageList(this);
	auto *cmbType = new QComboBox(this);
    auto *editMessage = new QTextEdit(this);
	auto *btnPost = new QPushButton(tr("Post"), this);
    auto *btnSendCompleted = new QPushButton(tr("Completed"), this);
    auto *btnDeletePending = new QPushButton(tr("Delete Pending"), this);
    auto *btnDeleteComleted = new QPushButton(tr("Delete All Comleted"), this);

    get_login = new QAction(this);
    get_login->setIcon(QIcon(":/pix/images/icons/login.png"));
    connect(get_login, &QAction::triggered, this, [CompletedList, messageList, this](){
            MainWindow::set_username(messageList, CompletedList);
    });
    pToolBar->addAction(get_login);
//    cmbType->addItem(QIcon(QPixmap(":/pix/images/icons/information.png")),
//                     "");
//    cmbType->addItem(QIcon(QPixmap(":/pix/images/icons/warning.png")),
//                     "");
//    cmbType->addItem(QIcon(QPixmap(":/pix/images/icons/error.png")),
//                     "");
    set_icon(cmbType);
	editMessage->setPlaceholderText(tr("Enter message here..."));

    //layoutToolbar->addWidget(pToolBar);
	layoutToolbar->addWidget(cmbType);
	layoutToolbar->addWidget(editMessage);
	layoutToolbar->addWidget(btnPost);

    qDebug("Row 1 selected");

    messageList->addMessage(tr("This is some text of an info message"),
                            QPixmap(":/pix/images/icons/information.png"),
                            QDateTime::currentDateTime(), 0, this, false);
    messageList->addMessage(tr("This is some text of a warning message"),
                            QPixmap(":/pix/images/icons/warning.png"),
                            QDateTime::currentDateTime(), 0, this, false);
    messageList->addMessage(tr("This is some text of an error message"),
                            QPixmap(":/pix/images/icons/error.png"),
                            QDateTime::currentDateTime(), 0, this, false);
    CompletedList->addMessage(tr("This is some text of an info message"),
                            QPixmap(":/pix/images/icons/ok.png"),
                            QDateTime::currentDateTime(), 1, this, false);
    CompletedList->addMessage(tr("This is some text of a warning message"),
                            QPixmap(":/pix/images/icons/ok.png"),
                            QDateTime::currentDateTime(), 1, this, false);
    CompletedList->addMessage(tr("This is some text of an error message"),
                            QPixmap(":/pix/images/icons/ok.png"),
                            QDateTime::currentDateTime(), 1, this, false);
//    pToolBar->addAction(btnDeletePending);
    auto *color = new QColorDialog;
    //layoutMain->addWidget(color);
    layoutMain->addWidget(pToolBar);
	layoutMain->addWidget(groupAdd);
	layoutMain->addWidget(messageList);
    layoutToolbar->addWidget(btnDeadline);
    layoutMain->addWidget(btnDeletePending);
    layoutMain->addWidget(btnSendCompleted);
    layoutMain->addWidget(CompletedList);
    layoutMain->addWidget(btnDeleteComleted);

//    forEach(messageList->model());

    resize(640, 480);
    connect(btnPost, &QPushButton::clicked, [messageList, cmbType,
            editMessage, a = this](){
        messageList->addMessage(editMessage->toPlainText(),
								cmbType->itemIcon(cmbType->currentIndex())
								.pixmap(48, 48),
                                QDateTime::currentDateTime(), 0, a, false);
    });
    connect(btnSendCompleted, &QPushButton::clicked, [messageList, CompletedList, a = this](){
        QModelIndex index = messageList->currentIndex();
        QVariant name = messageList->model()->data(index);
        CompletedList->addMessage(tr(name.toString().toUtf8().constData()),
                                QPixmap(":/pix/images/icons/ok.png"),
                                QDateTime::fromString(index.data(Qt::UserRole).toString().toUtf8().constData(), "yyyy-MM-dd hh:mm"), 1, a, false);
        messageList->clear_on_index(a);

    });
    connect(btnDeadline, &QPushButton::clicked, [messageList, cmbType,
                editMessage, a = this](){
            messageList->addMessage(editMessage->toPlainText(),
                                    cmbType->itemIcon(cmbType->currentIndex())
                                    .pixmap(48, 48),
                                    QDateTime::currentDateTime(), 0, a, true);
     });
    connect(btnDeletePending, &QPushButton::clicked, [messageList, a = this](){
        messageList->clear_on_index(a);
    });
    connect(btnDeleteComleted, &QPushButton::clicked, [CompletedList, a = this](){
        CompletedList->clearAll(a);
    });
}
