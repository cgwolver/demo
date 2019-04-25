#ifndef PICTUREBOX_H
#define PICTUREBOX_H

#include <QWidget>
#include <QImage>
#include <QPixmap>
#include <QBitmap>
#include <QGraphicsDropShadowEffect>

class PictureBox : public QWidget
{
    Q_OBJECT
public:
    enum PB_MODE {FIXED_SIZE, FIX_SIZE_CENTRED, AUTO_ZOOM, AUTO_SIZE};
    explicit PictureBox(QWidget *parent = 0);
    void setMode(PB_MODE mode);
    ~PictureBox();
    bool event(QEvent *event) override;

private:
    QGraphicsDropShadowEffect *shadow_effect ;
     QPixmap m_pixmap;
    //QBitmap m_mask;
    double m_scale;
    PB_MODE m_mode;
    QBrush m_brush;
protected:
	void mousePressEvent(QMouseEvent*e);
	void mouseMoveEvent(QMouseEvent*e);
	void mouseReleaseEvent(QMouseEvent*e);
    void paintEvent(QPaintEvent * event);
signals:

public slots:
    bool setImage(QImage &image, double scale = 1.0);
    void setBackground(QBrush brush);

};



#endif // PICTUREBOX_H
