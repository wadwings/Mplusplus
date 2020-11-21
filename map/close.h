#ifndef CLOSE_H
#define CLOSE_H
#include <QObject>
#include <QtWidgets>

class closetag: public QLabel
{
    Q_OBJECT
public:
    closetag(QWidget * parent = nullptr, int x = 0, int y = 0);
signals:
    void press();
protected:
    void mousePressEvent(QMouseEvent *ev) override;
};

#endif // CLOSE_H
