#include "widget.h"
#include "ui_widget.h"
#include <Qpainter>
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer.setInterval(1000);
    timer.start();
    connect(&timer,SIGNAL(timeout()),this,SLOT(changePos()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setRenderHint (QPainter:: Antialiasing);
    QPoint point(x,y);
    painter.drawEllipse(point,30,30);
}

void Widget::changePos()
{
    x = rand()%this->width();
    y = rand()%this->height() - ui->lcdNumber->height();
    this->repaint();
}
void Widget::mousePressEvent(QMouseEvent *eventPress)
{
    int _x = eventPress->x();
    int _y = eventPress->y();
    if((_x<=x+30 && _x>=x-30)&&(_y<=y+30 && _y>=y-30)) ui->lcdNumber->display(score++);
}
