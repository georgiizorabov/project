#include "MessageList.h"
#include "Delegate.h"
#include <QStandardItemModel>
#include <QDateTime>
#include "json.h"
#include <QStringListModel>
#include "server.h"
#include <QFuture>
#include <QtConcurrent/QtConcurrent>

MessageList::MessageList(QWidget *parent) :
	QListView(parent)
{
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
                             const QDateTime &dateTime, bool is_c, MainWindow *daddy)
{
	auto *item = new QStandardItem(QIcon(pixmap), text);

	item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    item->setData(dateTime.toString("yyyy-MM-dd hh:mm"), Qt::UserRole);

	static_cast<QStandardItemModel *>(model())->appendRow(item);
	scrollToBottom();
    if (is_c){
        daddy->j.update_completed(this->model());
    } else {
        daddy->j.update_in_progress(this->model());
    }
    QFuture<void> future = QtConcurrent::run(put_on_server, daddy->get_username().toStdString(), daddy->j.to_str_json());

}

void MessageList::clearAll(MainWindow *daddy)
{
	static_cast<QStandardItemModel *>(model())->clear();

        daddy->j.update_completed(this->model());
}

void MessageList::clear_on_index(MainWindow *daddy)
{
    QModelIndex oIndex = this->currentIndex();
    this->model()->removeRow(oIndex.row());
    daddy->j.update_in_progress(this->model());
}
