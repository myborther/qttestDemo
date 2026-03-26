#include "selfbutton.h"

SelfButton::SelfButton(QWidget *parent)
    : QWidget{parent}
{


}

void SelfButton::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setBrush(QColor("#000000"));

    for (QPair line : vDrawingLines) {
        painter.drawLine(line.first, line.second);
    }
    painter.end();
}

void SelfButton::mouseMoveEvent(QMouseEvent* ev)
{
    if (bIsPress) {
        vDrawingLines.append(qMakePair(mPoint, ev->pos()));
        mPoint = ev->pos();
        update();
    }
}

void SelfButton::mousePressEvent(QMouseEvent* ev)
{
    if (ev->button() == Qt::LeftButton) {
        bIsPress = true;
        mPoint = ev->pos();
    }
    else {
        bIsPress = false;
        vDrawingLines.clear();
        update();
    }
}

void SelfButton::mouseReleaseEvent(QMouseEvent*)
{
    bIsPress = false;
}
