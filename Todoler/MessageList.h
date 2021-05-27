#ifndef MESSAGELIST_H
#define MESSAGELIST_H

#include "MainWindow.h"
#include <QListView>

class MessageList : public QListView {
  Q_OBJECT
public:
  bool is_completed;
  explicit MessageList(QWidget *parent = nullptr);
  QAction *get_username = nullptr;
public slots:
  void addMessage(const QString &text, const QPixmap &pixmap,
                  const QDateTime &dateTime, bool is_c, MainWindow *daddy,
                  bool set_deadline, bool change_json = true);
  void clear_on_index(MainWindow *daddy);
  void clearAll(MainWindow *daddy);
};

#endif // MESSAGELIST_H
