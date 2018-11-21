#include "buttonlist.h"
#include <qevent.h>
#include <qpainter.h>
#include <QStylePainter>
#include <QMenu>

ListButton::ListButton(const QString &text, QWidget *parent)
	: QPushButton(text, parent)
{

}

void  ListButton::ListButton::enterEvent(QEvent *event) 
{
	QListWidget*list = dynamic_cast<QListWidget*>(parent());
	lw->itemEntered(lvi);
}

void ListButton::leaveEvent(QEvent *event)
{

}

void ListButton::paintEvent(QPaintEvent *e)
{
	if (isFlat()) {
		
		QPainter painter(this);	
		//if (isChecked()|| isDown())
		{
			QRect rtg = geometry();
			QRect rt;
			QColor c(255, 0, 0,0);
			painter.setPen(c);
			painter.setBrush(Qt::BrushStyle::NoBrush);
			rt.setLeft(0);
			rt.setTop(0);
			rt.setRight(rtg.right());
			rt.setBottom(rtg.height());
			bool last = false;
			bool first = false;
			
			QRect lw_rect = lw->geometry();
			QRect item_rect = lw->visualItemRect(lvi);

			if (item_rect.top() < item_rect.height())
				first = true;

			if (item_rect.bottom() + item_rect.height()/2 > lw_rect.height())
				last = true;

			if (first&&last)
			{
				rt.adjust(1, 0, -2, -2);
			}
			else
			{
				if (first)
					rt.adjust(1, 0, -2, 0);
				else if (last)
					rt.adjust(1, 0, -2, -2);
				else
					rt.adjust(1, 1, -2, -1);
			}
					
			QStyleOptionButton option;
			initStyleOption(&option);

		
			if (isCheckable())
			{
				if (isChecked() || isDown())
				{
					if (first || last)
						painter.setPen(QColor(192, 192, 192, 255));
					else
						//painter.setPen(QColor(255, 255, 255, 0));
						painter.setPen(QColor(192, 192, 192, 255));
					painter.setBrush(QColor(255, 255, 0, 255));
					
				}
				else if (option.state &QStyle::State_MouseOver)
				{
					//rt = style()->subElementRect(QStyle::SubElement::SE_PushButtonContents, &option, this);
					painter.setPen(QColor(255, 255, 255, 0));
					painter.setBrush(QColor(255, 255, 0, 64));
					
				}
			}
			else
			{
			if (option.state &QStyle::State_MouseOver)
			{
				//rt = style()->subElementRect(QStyle::SubElement::SE_PushButtonContents, &option, this);
				painter.setPen(QColor(255, 255, 255, 0));
				painter.setBrush(QColor(255, 255, 0, 64));

			}
			}


			painter.drawRect(rt);

			if (last==false)
				option.rect.adjust(1, 0, -1, 1);
			else
				option.rect.adjust(1, 0, -1, 0);
			QRect btn_rect = item_rect;
			btn_rect.setLeft(1);
			btn_rect.setTop(1);
		
			//if (option.state &QStyle::State_MouseOver)
			{
				//option.palette.setColor(QPalette::ButtonText, QColor(255, 0, 0,127));
				
			}
			//else
			{
				if (isChecked() || isDown())
				{
					option.palette.setColor(QPalette::ButtonText, QColor(255, 0, 0));
				}
				else
				{
					option.palette.setColor(QPalette::ButtonText, QColor(255, 255, 255));
				}
			}
			QStylePainter p(this);
			style()->drawControl(QStyle::CE_PushButtonLabel, &option, &p, this);
		}
		//else
		{
			//QPushButton::paintEvent(e);
		}
	}
	else
	{
		QPushButton::paintEvent(e);
	}
}

ButtonList::ButtonList(QWidget *parent )
    :QListWidget(parent)
{
	connect(this, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(itemChanged(QListWidgetItem*)));
	setMouseTracking(true);
	
}

void ButtonList::itemChanged(QListWidgetItem *item)
{
	QWidget* w = itemWidget(item);
	if (w)
	{
		ListButton* lb = (ListButton*)w;
		if (lb->text() != item->text())
		{
			lb->setText(item->text());
		}
	}
}

ListButton* ButtonList::addButtonItem(const QString& text,bool checkable)
{
	QListWidgetItem* lvi = new QListWidgetItem;
	
    int nn = 0;
    int hh = 40;
    setSpacing(nn);
	addItem(lvi);
    lvi->setSizeHint(QSize(0, hh));
	ListButton* btn1 = new ListButton(this);
	btn1->lvi = lvi;
	btn1->lw = this;
	btn1->setCheckable(checkable);
	btn1->setChecked(false);
	btn1->setText(text);
    btn1->setFlat(true);
	
	setItemWidget(lvi, btn1);
	QRect item_rect = visualItemRect(lvi);
	
   // resize(size().width(), item_rect.bottom()+nn+1);

	return btn1;
}

void ButtonList::resizeEvent(QResizeEvent *event)
{
	QListWidget::resizeEvent(event);
}

void ButtonList::paintEvent(QPaintEvent *e)
{
	
	//QListWidget::paintEvent(e);

	QPainter painter(viewport());
	QRect pg1 = geometry();
	QRect pg(1, 0, pg1.width()-2, pg1.height());
	//pg.moveTo(-pg.left(), -pg.top());
	painter.setPen(QColor(0, 0, 0, 0));
	painter.setBrush(QColor(0,0,0,200));
	painter.drawRect(pg);
	
	int last_checked = 0;
	for (int i = 0; i < count(); i++)
	{
		QListWidgetItem* lwi = item(i);
		QWidget* dw = itemWidget(lwi);
		ListButton*lb = (ListButton*)dw;
		QRect rt = lb->geometry();

		if (lb->isFlat()) 
		{
			if (!lb->isChecked())
			{
				//rt.setLeft(0);
				//rt.setTop(0);
				//rt.adjust(1, 1, -2, -2);

				//painter.drawRect(rt);

				//painter.drawLine(QLine(p1, p2));

				//QStylePainter p(this);
				//QStyleOptionButton option;
				//lb->initStyleOption(&option);
				//QMenu m;
				//m.initMen(&option);
				//option.features &= ~QStyleOptionButton::Flat;
				//p.setPen(c);
				//p.setBrush(Qt::BrushStyle::NoBrush);
				//painter.drawRect(rt);
				//style()->drawPrimitive(QStyle::PE_FrameGroupBox, &option, &p, this);
			}
		}
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
}
bool ButtonList::eventFilter(QObject *object, QEvent *event)
{
	if (object->metaObject() == &ListButton::staticMetaObject)
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
