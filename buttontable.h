#ifndef BUTTONTABLE_H
#define BUTTONTABLE_H

#include <QTreeWidget>
#include "itembutton.h"

class ButtonTable : public QTreeWidget
{
    Q_OBJECT
public:
    explicit ButtonTable(QWidget *parent = nullptr);
    ItemButton* addButtonItem(const QString& text, bool checkable);
    QTreeWidgetItem* buttonItem(ItemButton*btn);
    void paintEvent(QPaintEvent *) override;
	QModelIndex indexFromItem(QTreeWidgetItem *item);
    private slots:
    void itemChanged(QTreeWidgetItem *item, int column);
	
};

#endif // BUTTONTABLE_H
