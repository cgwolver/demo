#ifndef BUTTONLIST_H
#define BUTTONLIST_H

#include <QWidget>
#include <QListWidget>
#include <qpushbutton.h>
class ListButton :public QPushButton
{
	Q_OBJECT
public:
	explicit ListButton(QWidget *parent = nullptr):ListButton ("",parent) {}
	explicit ListButton(const QString &text, QWidget *parent = nullptr);
	void enterEvent(QEvent *event) override;
	void leaveEvent(QEvent *event) override;

    void paintEvent(QPaintEvent *) override;

	QListWidget* lw;
	QListWidgetItem* lvi;
};
class ButtonList : public QListWidget
{
	Q_OBJECT
public:
    explicit ButtonList(QWidget *parent = nullptr);
	bool eventFilter(QObject *object, QEvent *event)override;
	ListButton* addButtonItem(const QString& text , bool checkable);
	void resizeEvent(QResizeEvent *event) override;
	void paintEvent(QPaintEvent *) override;
private slots:
	void itemChanged(QListWidgetItem *item);
};

#endif // BUTTONLIST_H
