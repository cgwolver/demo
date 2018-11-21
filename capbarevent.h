#ifndef CAPBAREVENT_H
#define CAPBAREVENT_H

#include <QObject>
#include <mainwindow.h>
class CapBarEvent : public QObject
{
    Q_OBJECT
public:
    explicit CapBarEvent(QObject *parent = nullptr);
    Q_INVOKABLE void onClose();
    Q_INVOKABLE void onMaxi();
    Q_INVOKABLE void onMini();

signals:
	void minimize();
    void close();
    void maximize();
    
public slots:
};

#endif // CAPBAREVENT_H
