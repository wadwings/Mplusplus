#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
QT_BEGIN_NAMESPACE
namespace Ui { class PaintedWidget; }
QT_END_NAMESPACE

class PaintedWidget : public QWidget
{
    Q_OBJECT
public:
    PaintedWidget(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *);
};
#endif // MAINWINDOW_H
