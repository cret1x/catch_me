#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
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
    QTimer timer;
    int x = 0;
    int y = 0;
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *event);
    int score = 0;
private slots:
    void changePos();
};

#endif // WIDGET_H
