#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <Qtimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    t.setInterval(500);
    t.start();
    connect(&t,SIGNAL(timeout()),this,SLOT(makeRepaint()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent * e)
{
    QPainter painter(this);
    painter.setRenderHint (QPainter:: Antialiasing);
    int w = this->width();
    int h = this->height();
    int wstep = w/8;
    int hstep = h/8;
    QPoint point(w/2,h);
    int i = 0;
    while (i<7)
    {
                    painter.setBrush(QBrush(mas[rand()%6]));
                    painter.drawEllipse(point,w/2,h);
                    w = w-wstep;
                    h = h-hstep;
                    i++;
    }
    painter.setBrush(QBrush(Qt::white));
    painter.drawEllipse(point,w/2,h);

}

void Widget::makeRepaint()
{

 this->repaint();

}
