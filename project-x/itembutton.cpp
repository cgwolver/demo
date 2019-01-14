#include "itembutton.h"
#include <QPainter>
#include <QStylePainter>

ItemButton::ItemButton(const QString &text, QWidget *parent)
    : QPushButton(text, parent)
{
    connect(this,SIGNAL(toggled(bool)),this,SLOT(onToggled(bool)));
}

void ItemButton::initStyleOption(QStyleOptionButton *option) const
{
    QPushButton::initStyleOption(option);
}

void  ItemButton::enterEvent(QEvent *event)
{
    //QListWidget*list = dynamic_cast<QListWidget*>(parent());
    //lw->itemEntered(lvi);
}

void ItemButton::leaveEvent(QEvent *event)
{

}

void ItemButton::onToggled(bool checked)
{
    emit toggleSignal(this,checked);
}

void ItemButton::addjustRectToItemH(bool bAddjus, QRect& rect, int col_count)
{
	//QRect rtg = geometry();

	QRect rt;// = rect;
	rt.setLeft(0);
	rt.setTop(0);
	rt.setRight(rect.width());
	rt.setBottom(rect.height());

	bool last_item = false;
	bool first_item = false;

	int row = _idx.row();
	int col = _idx.column();

	if (col == 0)
		first_item = true;

	if (col_count == col + 1)
		last_item = true;

	if (first_item&&last_item)
	{
		rt.adjust(2, 1, -1, -1);
	}
	else
	{
		if (first_item)
			rt.adjust(1, 1, -1, -1);
		else if (last_item)
			rt.adjust(0, 1, -2, -1);
		else
			rt.adjust(1, 1, -1, -1);
	}

	_rect_to_item = rt;
}
void ItemButton::addjustRectToItemV(bool bAddjust, QRect& rect,int row_count)
{
	//QRect rtg = geometry();
	QRect rt;// = rect;
	rt.setLeft(0);
	rt.setTop(0);
	rt.setRight(rect.width());
	rt.setBottom(rect.height());

	bool last_row = false;
	bool first_row = false;

	int row = _idx.row();
	int col = _idx.column();

	if (row == 0)
		first_row = true;

	if (row_count == row + 1)
		last_row = true;

	if (first_row&&last_row)
	{
		rt.adjust(2, 0, -3, -2);
	}
	else
	{
		if (first_row)
			rt.adjust(2, 1, -3, 1);
		else if (last_row)
			rt.adjust(2, 1, -3, -2);
		else
			rt.adjust(2, 1, -3, -1);
	}

	_rect_to_item = rt;
}

void ItemButton::paintEvent(QPaintEvent *e)
{
    ItemButton* lb = this;
	
    if (lb->isFlat()) {

        QPainter painter(lb);
        //if (isChecked()|| isDown())
        {
            QColor c(255, 0, 0, 0);
            painter.setPen(c);
            painter.setBrush(Qt::BrushStyle::NoBrush);

            QStyleOptionButton option;
            lb->initStyleOption(&option);

            if (lb->isCheckable())
            {
                if (lb->isChecked() || lb->isDown())
                {
                    painter.setBrush(QColor(34, 87, 128, 255));

                }
                else if (option.state &QStyle::State_MouseOver)
                {
                    //rt = style()->subElementRect(QStyle::SubElement::SE_PushButtonContents, &option, this);
                    painter.setPen(QColor(255, 255, 255, 0));
                    painter.setBrush(QColor(34, 87, 128, 128));

                }
            }
            else
            {
				if (lb->isDown())
				{
					painter.setBrush(QColor(34, 87, 128, 255));
				}
				else if (option.state &QStyle::State_MouseOver)
                {
                    //rt = style()->subElementRect(QStyle::SubElement::SE_PushButtonContents, &option, this);
                    painter.setPen(QColor(255, 255, 255, 0));
                    painter.setBrush(QColor(34, 87, 128, 64));
                }
            }

            painter.drawRect(lb->_rect_to_item);


            //if (option.state &QStyle::State_MouseOver)
            {
                //option.palette.setColor(QPalette::ButtonText, QColor(255, 0, 0,127));

            }
            //else
            {
                if (lb->isChecked() || lb->isDown())
                {
                    option.palette.setColor(QPalette::ButtonText, QColor(255, 255, 255));
                }
                else
                {
                    option.palette.setColor(QPalette::ButtonText, QColor(255, 255, 255));
                }
            }
            QStylePainter p(lb);
            lb->style()->drawControl(QStyle::CE_PushButtonLabel, &option, &p, lb);
        }
        //else
        {
            //QPushButton::paintEvent(e);
        }
    }
    else
    {
        lb->paintEvent(e);
    }
}
