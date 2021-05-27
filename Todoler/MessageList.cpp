#include "MessageList.h"
#include "Delegate.h"
#include "json.h"
#include <QCalendarWidget>
#include <QDateTime>
#include <QDateTimeEdit>
#include <QFuture>
#include <QInputDialog>
#include <QStandardItemModel>
#include <QStringListModel>
#include <QtConcurrent/QtConcurrent>
#include <cpr/cpr.h>

std::string first_myurlEncode(std::string str) {
  std::string new_str = "";
  char c;
  int ic;
  const char *chars = str.c_str();
  char bufHex[10];
  int len = strlen(chars);

  for (int i = 0; i < len; i++) {
    c = chars[i];
    ic = c;
    // uncomment this if you want to encode spaces with +
    /*if (c==' ') new_str += '+';
    else */
    if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~')
      new_str += c;
    else {
      sprintf(bufHex, "%X", c);
      if (ic < 16)
        new_str += "%0";
      else
        new_str += "%";
      new_str += bufHex;
    }
  }
  return new_str;
}

void first_put_on_server(const std::string &name, const std::string &info) {
  qDebug() << "in put on server";
  std::string url = "https://rest-api-python.goshazorabov.repl.co/api/add/" +
                    first_myurlEncode(name) + "/" + first_myurlEncode(info);
  cpr::Response r = cpr::Get(cpr::Url{url}, cpr::VerifySsl{false});
}

MessageList::MessageList(QWidget *parent) : QListView(parent) {
  auto *delegate = new Delegate(this);
  QPalette p(palette());

  p.setBrush(QPalette::WindowText, QColor("#303030"));
  p.setBrush(QPalette::Base, QColor("#F0F1F2"));
  p.setBrush(QPalette::Light, QColor("#FFFFFF"));
  p.setBrush(QPalette::Midlight, QColor("#D3D6D8"));
  p.setBrush(QPalette::Mid, QColor("#C5C9Cb"));
  p.setBrush(QPalette::Dark, QColor("#9AA0A4"));
  p.setBrush(QPalette::Text, QColor("#616b71"));
  p.setBrush(QPalette::Highlight, QColor("#E2E4E5"));

  delegate->setContentsMargins(8, 8, 8, 8);
  delegate->setIconSize(32, 32);
  delegate->setHorizontalSpacing(8);
  delegate->setVerticalSpacing(4);

  setPalette(p);
  setFont(QFont("MSShellDlg 2", 12));
  setModel(new QStandardItemModel(this));
  setItemDelegate(delegate);
}

void MessageList::addMessage(const QString &text, const QPixmap &pixmap,
                             const QDateTime &dateTime, bool is_c,
                             MainWindow *daddy, bool set_deadline,
                             bool change_json) {
  auto *item = new QStandardItem(QIcon(pixmap), text);
  if (change_json) {
    QString deadline = "";
    QDateTime my_date;
    if (set_deadline) {
      QDateTimeEdit *dateEdit = new QDateTimeEdit(QDate::currentDate());
      //          dateEdit->setMinimumDate(QDate::currentDate().addDays(0));
      //          dateEdit->setFixedSize(500, 500);
      //          QFont serifFont("Times", 50, QFont::Bold);
      //          dateEdit->setFont(serifFont);
      //          dateEdit->setDisplayFormat("yyyy-MM-dd hh:mm");
      //          dateEdit->show();
      //          my_date = dateEdit->dateTime();
      //          qDebug() << my_date.toString();
    }
    //        while (my_date.isNull()) {
    //            QInputDialog my_dialog;
    //            my_dialog.setMinimumWidth(750);
    //            deadline = my_dialog.getText(this, tr("Input deadine in
    //            format: \"yyyy-MM-dd hh:mm\""),
    //                                                 tr("Deadline: "),
    //                                                 QLineEdit::QDateTimeEdit);
    //            my_date = QDateTime::fromString(deadline, "yyyy-MM-dd hh:mm");
    //        }
    item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    item->setData(dateTime.toString("yyyy-MM-dd hh:mm"), Qt::UserRole);
  } else {
    item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    //        item->setData(dateTime, Qt::UserRole);
    item->setData(dateTime.toString("yyyy-MM-dd hh:mm"), Qt::UserRole);
  }
  static_cast<QStandardItemModel *>(model())->appendRow(item);
  scrollToBottom();
  if (change_json) {
    if (is_c) {
      daddy->j.update_completed(this->model());
    } else {
      daddy->j.update_in_progress(this->model());
    }
  }
  qDebug() << daddy->j.j.dump(4).c_str();
  QFuture<void> future = QtConcurrent::run(first_put_on_server,
                                           daddy->get_username().toStdString(),
                                           daddy->j.to_str_json());
}

void MessageList::clearAll(MainWindow *daddy) {
  static_cast<QStandardItemModel *>(model())->clear();
  daddy->j.update_completed(this->model());
  QFuture<void> future = QtConcurrent::run(first_put_on_server,
                                           daddy->get_username().toStdString(),
                                           daddy->j.to_str_json());
}

void MessageList::clear_on_index(MainWindow *daddy) {
  QModelIndex oIndex = this->currentIndex();
  this->model()->removeRow(oIndex.row());
  daddy->j.update_in_progress(this->model());
  QFuture<void> future = QtConcurrent::run(first_put_on_server,
                                           daddy->get_username().toStdString(),
                                           daddy->j.to_str_json());
}
