#include "MainWindow.h"
#include "MessageList.h"
#include "server.h"
#include <QBoxLayout>
#include <QCalendarWidget>
#include <QColorDialog>
#include <QComboBox>
#include <QDateTime>
#include <QDateTimeEdit>
#include <QDebug>
#include <QFuture>
#include <QGroupBox>
#include <QInputDialog>
#include <QLabel>
#include <QLayout>
#include <QLineEdit>
#include <QListView>
#include <QMenuBar>
#include <QPushButton>
#include <QStandardItemModel>
#include <QTextEdit>
#include <QToolBar>
#include <QtConcurrent/QtConcurrent>
#include <boost/filesystem.hpp>
#include <cpr/cpr.h>
#include <dirent.h>
#include <filesystem>
#include <iostream>
#include <qlistview.h>
#include <sstream>
#include <stdio.h>
#include <string>

QString MainWindow::get_username() const { return username; }

void MainWindow::set_email() {
  if (get_username().size() == 0) {
    return;
  }
  QString take_email = QInputDialog::getText(
      this, tr("Input your email"), tr("User email:"), QLineEdit::Normal);
  email = take_email;
  j.j["email"] = email.toStdString();
  QFuture<void> future = QtConcurrent::run(
      put_on_server, get_username().toStdString(), j.to_str_json());
}

void MainWindow::set_colour() {
  QColor new_color = QColorDialog::getColor();
  if (new_color.isValid()) {
    colour = new_color;
    QPalette pal1;
    pal1.setColor(this->backgroundRole(), colour);
    this->setPalette(pal1);
    j.j["background_colour"] = colour.name().toUtf8().constData();
    QFuture<void> future = QtConcurrent::run(
        put_on_server, get_username().toStdString(), j.to_str_json());
  }
}

void MainWindow::set_username(MessageList *ml, MessageList *cl) {
  QString text = QInputDialog::getText(this, tr("Input your username"),
                                       tr("User name:"), QLineEdit::Normal);
  if (!text.isEmpty()) {
    username = text;
    j.j["username"] = username.toStdString();
    j.j = json::parse(
        get_from_server(username.toStdString())); //Передть строку из сервера
    qDebug() << "==============\n" << j.to_str_json().c_str(); // проверка
    to_list(ml, cl);
  }
  if (j.j["email"] == "") { // check if email already exists
    QString text1 = QInputDialog::getText(this, tr("Input your email"),
                                          tr("User email:"), QLineEdit::Normal);
    if (!text1.isEmpty()) {
      email = text1;
      put_email_on_server(email.toStdString());
      j.j["email"] = email.toStdString();
    }
  }
  if (j.j["background_colour"] != "") {
    QPalette pal1;
    for (auto &element : j.j["background_colour"].items()) {
      colour.setNamedColor(element.value().dump(4).c_str());
      pal1.setColor(this->backgroundRole(), colour);
      this->setPalette(pal1);
    }
  }
  // qDebug() << j.j.dump(4).c_str();j.j["background_colour"] = colour.value();
}

void MainWindow::to_list(MessageList *ml, MessageList *cl) {
  static_cast<QStandardItemModel *>(ml->model())->clear();
  static_cast<QStandardItemModel *>(cl->model())->clear();
  for (auto &element : j.j["Progress"].items()) {
    std::string todo = element.value()[0].dump(4);
    std::string date = element.value()[1].dump(4);
    ////        qDebug() << todo.substr(1, todo.size() - 2).c_str() << "\t" <<
    ///date.substr(1, date.size() - 2).c_str();
    if (date.size() <= 2) {
      ml->addMessage(tr(todo.substr(1, todo.size() - 2).c_str()),
                     QPixmap(":/pix/images/icons/information.png"),
                     QDateTime::fromString(""), 0, this, false, false);
    } else {
      ml->addMessage(
          tr(todo.substr(1, todo.size() - 2).c_str()),
          QPixmap(":/pix/images/icons/information.png"),
          QDateTime::fromString(date.substr(1, date.size() - 2).c_str(),
                                "yyyy-MM-dd hh:mm"),
          0, this, false, false);
    }
  }
  for (auto &element : j.j["Completed"].items()) {
    std::string todo = element.value()[0].dump(4);
    std::string date = element.value()[1].dump(4);
    ////        qDebug() << todo.substr(1, todo.size() - 2).c_str() << "\t" <<
    ///date.substr(1, date.size() - 2).c_str();
    if (date.size() <= 2) {
      cl->addMessage(tr(todo.substr(1, todo.size() - 2).c_str()),
                     QPixmap(":/pix/images/icons/ok.png"),
                     QDateTime::fromString(""), 1, this, false, false);
    } else {
      cl->addMessage(
          tr(todo.substr(1, todo.size() - 2).c_str()),
          QPixmap(":/pix/images/icons/ok.png"),
          QDateTime::fromString(date.substr(1, date.size() - 2).c_str(),
                                "yyyy-MM-dd hh:mm"),
          1, this, false, false);
    }
  }
}

void MainWindow::set_icon(QComboBox *box) {
  for (boost::filesystem::recursive_directory_iterator
           it("../Todoler/images/icons"),
       end;
       it != end; ++it) {
    if (it->path().extension() == ".png") {
      std::stringstream ss;
      ss << *it;
      std::string str = ss.str();
      std::cout << str.substr(25, str.size() - 26) << std::endl;
      box->addItem(QIcon(QPixmap(
                       (":/pix/images/icons/" + str.substr(25, str.size() - 26))
                           .c_str())),
                   "");
    }
  }
}

void MainWindow::read_all_icons() {
  for (boost::filesystem::recursive_directory_iterator
           it("../Todoler/images/icons"),
       end;
       it != end; ++it) {
    if (it->path().extension() == ".png") {
      std::stringstream ss;
      ss << *it;
      std::string str = ss.str();
      //   std::cout << str.substr(25, str.size() - 26) << std::endl;
    }
  }
}

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
  QPalette pal1;
  pal1.setColor(this->backgroundRole(), colour);
  this->setPalette(pal1);
  // QColor new_color = QColorDialog::getColor();
  auto *btnDeadline = new QPushButton(tr("Post with deadline"), this);
  auto *layoutMain = new QVBoxLayout(this);
  auto *groupAdd = new QGroupBox(this);
  groupAdd->setMaximumHeight(200);
  auto *groupPending = new QGroupBox(this);
  auto *groupCompleted = new QGroupBox(this);
  auto *layoutAddingMessages = new QHBoxLayout(groupAdd);
  auto *layoutPending = new QHBoxLayout(groupPending);
  auto *layoutCompleted = new QHBoxLayout(groupCompleted);
  auto *messageList = new MessageList(this);
  auto *CompletedList = new MessageList(this);
  auto *cmbType = new QComboBox(this);
  auto *editMessage = new QTextEdit(this);
  auto *btnPost = new QPushButton(tr("Post without deadline"), this);
  auto *btnSendCompleted = new QPushButton(tr("Completed"), this);
  auto *btnChangePending = new QPushButton(tr("Change"), this);
  auto *btnDeletePending = new QPushButton(tr("Delete Pending"), this);
  auto *btnDeleteComleted_index = new QPushButton(tr("Delete Completed"), this);
  auto *btnDeleteComleted = new QPushButton(tr("Delete All Comleted"), this);

  auto *layoutPending_all = new QVBoxLayout();
  auto *layoutCompleted_all = new QVBoxLayout();
  auto *layout_all = new QHBoxLayout();
  auto get_login = new QAction(tr("Login"), this);
  auto change_background = new QAction(tr("Background"), this);
  auto get_email = new QAction(tr("Email"), this);
  get_login->setIcon(QIcon(":/pix/images/icons/login.png"));
  connect(get_login, &QAction::triggered, this,
          [CompletedList, messageList, this]() {
            MainWindow::set_username(messageList, CompletedList);
          });
  connect(get_email, &QAction::triggered, this,
          [a = this]() { a->set_email(); });
  connect(change_background, &QAction::triggered, this,
          [a = this]() { a->set_colour(); });
  QMenuBar *menubar = new QMenuBar;
  QMenu *User_menu = new QMenu("&User");
  QMenu *Custom = new QMenu("&Customize");
  User_menu->addAction(get_login);
  User_menu->addAction(get_email);
  Custom->addAction(change_background);
  menubar->addMenu(User_menu);
  menubar->addMenu(Custom);
  //    cmbType->addItem(QIcon(QPixmap(":/pix/images/icons/information.png")),
  //                     "");
  //    cmbType->addItem(QIcon(QPixmap(":/pix/images/icons/warning.png")),
  //                     "");
  //    cmbType->addItem(QIcon(QPixmap(":/pix/images/icons/error.png")),
  //                     "");
  set_icon(cmbType);
  editMessage->setPlaceholderText(tr("Enter todo here..."));

  // layoutToolbar->addWidget(pToolBar);

  qDebug("Row 1 selected");

  auto *groupMessage_left = new QGroupBox(this);
  auto *layoutMessage_left = new QHBoxLayout(groupMessage_left);
  auto *groupMessage_right = new QGroupBox(this);
  auto *layoutMessage_right = new QVBoxLayout(groupMessage_right);

  messageList->addMessage(tr("Today I should finish my mathlogical problem and "
                             "after this try to solve contest"),
                          QPixmap(":/pix/images/icons/information.png"),
                          QDateTime::currentDateTime(), 0, this, false);
  messageList->addMessage(tr("I have gym today, I can't miss it"),
                          QPixmap(":/pix/images/icons/warning.png"),
                          QDateTime::currentDateTime(), 0, this, false);
  messageList->addMessage(tr("I have a date today"),
                          QPixmap(":/pix/images/icons/error.png"),
                          QDateTime::currentDateTime(), 0, this, false);
  CompletedList->addMessage(tr("Go for a walk with a dog"),
                            QPixmap(":/pix/images/icons/ok.png"),
                            QDateTime::currentDateTime(), 1, this, false);
  CompletedList->addMessage(tr("Help mom with dishes"),
                            QPixmap(":/pix/images/icons/ok.png"),
                            QDateTime::currentDateTime(), 1, this, false);
  CompletedList->addMessage(tr("Hang out with friends"),
                            QPixmap(":/pix/images/icons/ok.png"),
                            QDateTime::currentDateTime(), 1, this, false);
  //    pToolBar->addAction(btnDeletePending);
  QDateTimeEdit *DateTime = new QDateTimeEdit(QDate::currentDate());
  DateTime->setMinimumDate(QDate::currentDate().addDays(0));
  DateTime->setMinimumTime(QTime::currentTime());
  DateTime->setDisplayFormat("yyyy-MM-dd hh:mm");

  layoutPending->addWidget(btnDeletePending);
  layoutPending->addWidget(btnChangePending);
  layoutPending->addWidget(btnSendCompleted);

  layoutCompleted->addWidget(btnDeleteComleted);
  layoutCompleted->addWidget(btnDeleteComleted_index);


  layoutMessage_left->addWidget(cmbType);
  layoutMessage_left->addWidget(editMessage);
  layoutMessage_right->addWidget(DateTime);
  layoutMessage_right->addWidget(btnDeadline);
  layoutMessage_right->addWidget(btnPost);
  layoutAddingMessages->addWidget(groupMessage_left);
  layoutAddingMessages->addWidget(groupMessage_right);

  layoutMain->addWidget(menubar);
  // layoutMain->addWidget(pToolBar);
  layoutMain->addWidget(groupAdd);
  layoutPending_all->addWidget(messageList);
  layoutPending_all->addWidget(groupPending);
  layoutCompleted_all->addWidget(CompletedList);
  layoutCompleted_all->addWidget(groupCompleted);
  layout_all->addLayout(layoutPending_all);
  layout_all->addLayout(layoutCompleted_all);
  layoutMain->addLayout(layout_all);
  //    forEach(messageList->model());

  resize(640, 480);
  connect(btnPost, &QPushButton::clicked,
          [messageList, cmbType, editMessage, a = this]() {
            messageList->addMessage(
                editMessage->toPlainText(),
                cmbType->itemIcon(cmbType->currentIndex()).pixmap(48, 48),
                QDateTime::fromString(""), 0, a, false);
          });
  connect(btnSendCompleted, &QPushButton::clicked,
          [messageList, CompletedList, a = this]() {
            QModelIndex index = messageList->currentIndex();
            QVariant name = messageList->model()->data(index);
            CompletedList->addMessage(
                tr(name.toString().toUtf8().constData()),
                QPixmap(":/pix/images/icons/ok.png"),
                QDateTime::fromString(
                    index.data(Qt::UserRole).toString().toUtf8().constData(),
                    "yyyy-MM-dd hh:mm"),
                1, a, false);
            messageList->clear_on_index(a);
          });
  connect(btnChangePending, &QPushButton::clicked,
          [DateTime, editMessage, messageList, a = this]() {
            QModelIndex index = messageList->currentIndex();
            QVariant name = messageList->model()->data(index);
            editMessage->setText(name.toString());
            messageList->clear_on_index(a);
          });
  connect(btnDeadline, &QPushButton::clicked,
          [messageList, cmbType, DateTime, editMessage, a = this]() {
            messageList->addMessage(
                editMessage->toPlainText(),
                cmbType->itemIcon(cmbType->currentIndex()).pixmap(48, 48),
                DateTime->dateTime(), 0, a, true);
          });
  connect(btnDeletePending, &QPushButton::clicked,
          [messageList, a = this]() { messageList->clear_on_index(a); });
  connect(btnDeleteComleted, &QPushButton::clicked,
          [CompletedList, a = this]() { CompletedList->clearAll(a); });
  connect(btnDeleteComleted_index, &QPushButton::clicked,
          [CompletedList, a = this]() { CompletedList->clear_on_index(a); });
}
