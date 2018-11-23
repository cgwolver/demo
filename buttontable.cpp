#include "buttontable.h"
#include <QPainter>
ButtonTable::ButtonTable(QWidget *parent )
    :QTreeWidget(parent)
{
	setHeaderHidden(true);
	//setSelectionMode(NoSelection);
	setIndentation(0);
	addTopLevelItem(new QTreeWidgetItem);
	connect(this, SIGNAL(itemChanged(QTreeWidgetItem *, int)), this, SLOT(itemChanged(QTreeWidgetItem *, int)));
}

void ButtonTable::itemChanged(QTreeWidgetItem *item, int column)
{
    QWidget* w = itemWidget(item, column);
    if (w)
    {
        ItemButton* lb = (ItemButton*)w;
        if (lb->text() != item->text(column))
        {
            lb->setText(item->text(column));
        }
    }
}

QTreeWidgetItem* ButtonTable::buttonItem(ItemButton*btn )
{
    return itemFromIndex(btn->_idx);
}
QModelIndex ButtonTable::indexFromItem(QTreeWidgetItem *item,int col)
{
	return QTreeWidget::indexFromItem(item, col);
}
ItemButton* ButtonTable::addButtonItem(const QString& text, bool checkable)
{
    QTreeWidgetItem* lwi = topLevelItem(0);
	
    int hh = 40;
	int ww = 100;

	int column = lwi->columnCount();

	int new_column_count = column + 1;
	
	setColumnCount(new_column_count);
	setColumnWidth(column, ww);
	resize((ww)* (new_column_count), hh);
  
	lwi->setSizeHint(column,QSize(ww, hh));
    ItemButton* lb = new ItemButton(this);
	lb->setGeometry(0, 0, ww, hh);

    lb->_ww = this;
    lb->setCheckable(checkable);
    lb->setChecked(false);
    lb->setFlat(true);

	lb->setMinimumSize(QSize(0, 0));
	lb->setMaximumSize(QSize(ww, hh));

    setItemWidget(lwi, column, lb);
	
	lb->_idx = indexFromItem(lwi, column);

    setMouseTracking(true);

	QRect item_rect = visualRect(lb->_idx);// lb->geometry();

	int row = lb->_idx.row();
	int col = lb->_idx.column();

	lb->addjustRectToItemH(true, item_rect, new_column_count);

	if (col >= 1)
	{
		QWidget* wgt = itemWidget(lwi, column);
		if (wgt)
		{
			ItemButton*ib = (ItemButton*)wgt;
			QRect item_rect = visualRect(ib->_idx);	
			ib->addjustRectToItemH(true, item_rect, new_column_count);
		}
	}

    //QRect rt;

   // rt.setLeft(0);
   // rt.setTop(1);
   // rt.setRight(rtg.width()-1);
   // rt.setBottom(rtg.height());

   // lb->_rect_to_item = rt;
	lwi->setText(column, text);

    return lb;
}


void ButtonTable::paintEvent(QPaintEvent *e)
{
    //QTreeWidget::paintEvent(e);
    QPainter painter(viewport());
    QRect pg1 = geometry();
    QRect pg(1, 0, pg1.width()-2, pg1.height()-1);
    //pg.moveTo(-pg.left(), -pg.top());
    painter.setPen(QColor(0, 0, 0, 255));
    painter.setBrush(QColor(0,64,35,200));
    painter.drawRect(pg);

#if 0
    int last_checked = 0;

    for (int i = 0; i < count(); i++)
    {
        QTreeWidgetItem* lwi = item(i);
        QWidget* dw = itemWidget(lwi);
        ItemButton*lb = (ItemButton*)dw;
        QRect rt = lb->geometry();

        QColor c(0, 0, 64);
        painter.setPen(c);
        painter.setBrush(QColor(100, 160, 0, 64));

        if (lb->isFlat())
        {
            //if (!lb->isChecked())
            {
                rt.adjust(1, 0, -1, 0);
                QPoint p1(0, 0), p2(0, 0);
                if (last_checked)
                {
                    //rt.adjust(0, -1, 0, 0);
                }

                p1.setX(rt.left());
                p2.setX(rt.right());

                int h = rt.top();
                p1.setY(h);
                p2.setY(h);

                painter.drawLine(QLine(p1, p2));

                if (i == count() - 1)
                {
                    p1.setY(rt.bottom());
                    p2.setY(rt.bottom());
                    painter.drawLine(QLine(p1, p2));
                }

                QPoint p3(rt.left(), rt.top()), p4(rt.left(), rt.bottom());
                painter.drawLine(QLine(p3, p4));

                QPoint p5(rt.right(), rt.top()), p6(rt.right(), rt.bottom());
                painter.drawLine(QLine(p5, p6));
            }
        }

        painter.setPen(QColor(0,0,0,0));
        painter.setBrush(QColor(100, 160, 0, 64));
        //painter.drawRect(rt);
        last_checked = lb->isChecked() ? 1 : 0;
    }
#endif
}
#if 0
bool ButtonTable::eventFilter(QObject *object, QEvent *event)
{
    if (object->metaObject() == &ItemButton::staticMetaObject)
    {
        if (event->type() == QEvent::FocusIn)
        {
            //return false;
        }
        if (event->type() == QEvent::FocusOut)
        {
            return false;
        }
    }
    return QTreeWidget::eventFilter(object,event);
}
#endif
