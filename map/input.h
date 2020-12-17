#ifndef __INPUT__
#define __INPUT__
#include <QObject>
#include <QtWidgets>
#include <iostream>

class input : public QTextEdit{
    Q_OBJECT
public:
    QTimer time1;
    int focus = 0;
    input(QWidget *parent = nullptr);
public slots:
    void slot_getfocus();
    void slot_losefocus();
signals:
    void getfocus();
    void losefocus();
protected:
    void enterEvent(QEvent *ev) override;
    void leaveEvent(QEvent *ev) override;
};
#endif
