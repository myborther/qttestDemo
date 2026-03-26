#ifndef SELFBUTTON_H
#define SELFBUTTON_H

#include <QPixmap>
#include <QLayout>
#include <QPainter>
#include <QPair>
#include <QPoint>
#include <QVector>
#include <QWidget>
#include <QMouseEvent>

class SelfButton : public QWidget
{
    Q_OBJECT

public:
    SelfButton(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* ev) override;
    void mouseMoveEvent(QMouseEvent* ev) override;
    void mousePressEvent(QMouseEvent* ev) override;
    void mouseReleaseEvent(QMouseEvent* ev) override;

private:
    bool bIsPress;

    // 起点
    QPoint mPoint;

    // 缓存线段
    QVector<QPair<QPoint, QPoint>> vDrawingLines;

    // 缓存椭圆

};

#endif // SELFBUTTON_H
