#ifndef BUTTONLIST_H
#define BUTTONLIST_H

#include <QWidget>
#include <QListWidget>


#include "itembutton.h"

class ButtonList : public QListWidget
{
	Q_OBJECT
public:
    explicit ButtonList(QWidget *parent = nullptr);
	//bool eventFilter(QObject *object, QEvent *event)override;
	ItemButton* addButtonItem(QListWidgetItem* item , bool checkable);
	QListWidgetItem* buttonItem(ItemButton*);
	void paintEvent(QPaintEvent *) override;
private slots:
	void itemChanged(QListWidgetItem *item);
    void itemToggled(ItemButton*btn,bool checked);
};


#endif // BUTTONLIST_H
