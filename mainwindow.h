#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QTreeWidget>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void mouseDoubleClickEvent(QMouseEvent *event) override;
	void mouseReleaseEvent(QMouseEvent *event) override;
	void mousePressEvent(QMouseEvent *event) override;
	void mouseMoveEvent(QMouseEvent *event) override;
	void resizeEvent(QResizeEvent *event)override;
	QRect childWindowRect(QWidget*child);
private slots:
    void QListWidget_itemEntered(QListWidgetItem *item);
    void QListWidget_itemChanged(QListWidgetItem *item);
    void QListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
	void QTableWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);
    void ListButton_toggled(bool);
    void onClose();
    void onMaximize();
    void onMinimize();
	
private:
    Ui::MainWindow *ui;
	QPoint _mousePt;
};

#endif // MAINWINDOW_H
