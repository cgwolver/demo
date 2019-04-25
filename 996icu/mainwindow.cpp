#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qrencode.h>
#include <picturebox.h>
#include <array>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    std::array<int, 4> cpui;
    __cpuid(cpui.data(), 0x0);    //cpui[0] = "funcition_id的最大值"
    int nIds_ = cpui[0];
    std::vector<std::array<int, 4>> data_;  //保存遍历到的所有cpui的值
    for (int i = 0; i <= nIds_; ++i)
    {
        __cpuidex(cpui.data(), i, 0);
        data_.push_back(cpui);
    }
    //reinterpret_cast<int*>(vendor) //*reinterpret_cast<int*>(vendor)
    //索引0 0+4 0+8的值构成了CPU芯片的名称
    char vendor_[0x20] = { 0 };
    *reinterpret_cast<int*>(vendor_) = data_[0][1];
    *reinterpret_cast<int*>(vendor_ + 4) = data_[0][3];
    *reinterpret_cast<int*>(vendor_ + 8) = data_[0][2];  // vendor="GenuineIntel"

    std::string vendor = vendor_;

    char sn[256];
    sprintf_s(sn, sizeof(sn), "%08X%08X", data_[1][3], data_[1][0]);

    char url[256] = { 0 };
    sprintf_s(url, sizeof(url), "http://www.knowget.io/996.icu?vendor=%s&id=%s", vendor.c_str(),sn);

    QRcode *qrcode = QRcode_encodeString(url, 0, QR_ECLEVEL_H, QR_MODE_8, 0);

    int h = qrcode->width;
    int w = qrcode->width;

    int ex = 16;
    int ey = 16;

    QImage img(w * 8 + ex*2, h * 8 + ey*2, QImage::Format_RGB888);
    img.fill(qRgb(255,0,0));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            unsigned char dat = qrcode->data[i*w + j];

            for (int k = 0; k < 8; k++)
            {
                for (int l = 0; l < 8; l++)
                {
                    if (dat & 1)
                    {
                        img.setPixel(ex+j * 8 + l,ey+i * 8 + k,  qRgb(0, 0, 0));
                    }
                    else
                    {
                        img.setPixel( ex+j * 8 + l,ey+i * 8 + k, qRgb(255, 255, 255));
                    }
                }
            }
        }
    }

    QRcode_free(qrcode);

    PictureBox* widget = ui->widget;
    widget->setImage(img);

    resize(img.width(),img.height());
    widget->setGeometry(0,0,img.width(),img.height());

    widget->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
