#include "itembutton.h"
#include <QPainter>
#include <QStylePainter>

ItemButton::ItemButton(const QString &text, QWidget *parent)
    : QPushButton(text, parent)
{
}

void ItemButton::initStyleOption(QStyleOptionButton *option) const
{
    QPushButton::initStyleOption(option);
}

void  ItemButton::ItemButton::enterEvent(QEvent *event)
{
    //QListWidget*list = dynamic_cast<QListWidget*>(parent());
    //lw->itemEntered(lvi);
}

void ItemButton::leaveEvent(QEvent *event)
{

}

void ItemButton::addjustRectToItem(bool bAddjust, QRect& rect,int row_count)
{
	QRect rtg = geometry();
	QRect rt = rect;
	rt.setLeft(0);
	rt.setTop(0);
	rt.setRight(rtg.right());
	rt.setBottom(rtg.height());

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
		rt.adjust(1, 0, -2, -2);
	}
	else
	{
		if (first_row)
			rt.adjust(1, 1, -2, 1);
		else if (last_row)
			rt.adjust(1, 1, -2, -2);
		else
			rt.adjust(1, 1, -2, -1);
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
                    painter.setBrush(QColor(113, 205, 157, 255));

                }
                else if (option.state &QStyle::State_MouseOver)
                {
                    //rt = style()->subElementRect(QStyle::SubElement::SE_PushButtonContents, &option, this);
                    painter.setPen(QColor(255, 255, 255, 0));
                    painter.setBrush(QColor(113, 205, 157, 64));

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

            painter.drawRect(lb->_rect_to_item);


            //if (option.state &QStyle::State_MouseOver)
            {
                //option.palette.setColor(QPalette::ButtonText, QColor(255, 0, 0,127));

            }
            //else
            {
                if (lb->isChecked() || lb->isDown())
                {
                    option.palette.setColor(QPalette::ButtonText, QColor(255, 0, 0));
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
