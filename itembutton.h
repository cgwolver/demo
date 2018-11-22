#ifndef ITEMBUTTON_H
#define ITEMBUTTON_H
#include <QWidget>
#include <QPushButton>
#include <QModelIndex>
#include <QEvent>
#include <QStyleOptionButton>
class ItemButton :public QPushButton
{
    Q_OBJECT
public:
    explicit ItemButton(QWidget *parent = nullptr):ItemButton("",parent) {}
    explicit ItemButton(const QString &text, QWidget *parent = nullptr);

    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void paintEvent(QPaintEvent *) override;
    void initStyleOption(QStyleOptionButton *option) const;

	void addjustRectToItem(bool bAddjus, QRect& rect, int row_count);
    QWidget* _ww;
    QModelIndex _idx;
    QRect _rect_to_item;
};

#endif // ITEMBUTTON_H
