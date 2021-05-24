#ifndef MESSAGELIST_H
#define MESSAGELIST_H

#include <QListView>

class MessageList : public QListView
{
	Q_OBJECT
public:
    explicit MessageList(QWidget *parent = nullptr);
    QAction *get_username = nullptr;
public slots:
    void addMessage(const QString &text, const QPixmap &pixmap, const QDateTime &dateTime);
    void clear_on_index();
	void clearAll();
};

#endif // MESSAGELIST_H
