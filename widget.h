#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <Qtimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QTimer t;
    int r = 0;
    int g = 0;
    int b = 0;
    QColor mas[6] = {Qt::red,Qt::blue,Qt::green,Qt::magenta,Qt::yellow,Qt::cyan};
protected:
    void paintEvent(QPaintEvent *e);
    void makeRepaint();
};

#endif // WIDGET_H
