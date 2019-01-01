#include "buttonlist.h"
#include <qevent.h>
#include <qpainter.h>
#include <QStylePainter>
#include <QMenu>
#include <qapplication.h>

ButtonList::ButtonList(QWidget *parent )
    :QListWidget(parent)
{
	connect(this, SIGNAL(itemChanged(QListWidgetItem *)), this, SLOT(itemChanged(QListWidgetItem *)));
}

void ButtonList::itemChanged(QListWidgetItem *item)
{
	QWidget* w = itemWidget(item);
	if (w)
	{
		ItemButton* lb = (ItemButton*)w;
		if (lb->text() != item->text())
		{
			lb->setText(item->text());
		}
	}
}

QListWidgetItem* ButtonList::buttonItem(ItemButton*btn )
{
	return itemFromIndex(btn->_idx);
}

ItemButton* ButtonList::addButtonItem( QListWidgetItem*itEM,bool checkable)
{
	QListWidgetItem* lwi = itEM;
	
    int nn = 0;
    int hh = 50;
    setSpacing(nn);
	addItem(lwi);
    lwi->setSizeHint(QSize(0, hh));
	ItemButton* lb = new ItemButton(this);
	
	lb->_ww = this;
	lb->setCheckable(checkable);
	lb->setChecked(false);
	lb->setFlat(true);
	
	setItemWidget(lwi, lb);
	lb->_idx = indexFromItem(lwi);
	
	setMouseTracking(true);

	QRect item_rect = visualItemRect(lwi);

	int row = lb->_idx.row();
	int col = lb->_idx.column();

	lb->addjustRectToItemV(true, item_rect,count());

	if (row >= 1)
	{
		QListWidgetItem*it = item(row - 1);
		QWidget* wgt = itemWidget(it);
		if (wgt)
		{
			QRect item_rect = visualItemRect(it);
			ItemButton*ib = (ItemButton*)wgt;
			ib->addjustRectToItemV(true, item_rect,count());
		}
	}

	
    //resize(size().width(), item_rect.bottom()+nn+1);

	return lb;
}

#define DRAW_ITEM_FRAME 0

void ButtonList::paintEvent(QPaintEvent *e)
{
	//QListWidget::paintEvent(e);
	QPainter painter(viewport());
	QRect pg1 = geometry();
	QRect pg(0, 0, pg1.width(), pg1.height());
	//pg.moveTo(-pg.left(), -pg.top());
	painter.setPen(QColor(64, 64, 64, 128));
	//painter.setBrush(QColor(32,85,138,255));
	painter.setBrush(QColor(64, 64, 64, 128));
    painter.fillRect(pg, QColor(64, 64, 164, 128));
	
	int last_checked = 0;
	
	for (int i = 0; i < count(); i++)
	{
		QListWidgetItem* lwi = item(i);
		QWidget* dw = itemWidget(lwi);
		ItemButton*lb = (ItemButton*)dw;
		QRect rt = lb->geometry();

		QColor c(0, 55, 64);
		painter.setPen(c);
		painter.setBrush(QColor(100, 160, 0, 64));

		if (lb->isFlat())
		{
#if DRAW_ITEM_FRAME
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
#endif
		}
		
		painter.setPen(QColor(0,0,0,0));
		painter.setBrush(QColor(100, 160, 0, 64));
		
		//painter.drawRect(rt);
		last_checked = lb->isChecked() ? 1 : 0;
	}
}
#if 0
bool ButtonList::eventFilter(QObject *object, QEvent *event)
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
	return QListWidget::eventFilter(object,event);
}
#endif
