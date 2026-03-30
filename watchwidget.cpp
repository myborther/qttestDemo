#include "watchwidget.h"
#include "ui_watchwidget.h"

#include <QDateTime>
#include <QGraphicsDropShadowEffect>
#include <QPainter>
#include <QPainterPath>
#include <QTimer>

WatchWidget::WatchWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WatchWidget)
{
    ui->setupUi(this);

    // 无边框
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    // 透明
    //setAttribute(Qt::WA_TranslucentBackground);
    //setStyleSheet("background-color: transparent;");

    // 边框
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(0);
    shadow->setColor(QColor(255,255,255,255));
    shadow->setBlurRadius(16);
    this->setGraphicsEffect(shadow);

    QTimer* timer = new QTimer(this);

    connect(timer,&QTimer::timeout,this,[&](){
        this->update();
    });

    timer->start(1000);
}

WatchWidget::~WatchWidget()
{
    delete ui;
}

///
/// \brief WatchWidget::drawSecond 画秒针
///
void WatchWidget::drawSecond(QPainter& painter,int second)
{
    painter.save();

    painter.setPen(QPen(QColor("#999999"),2));

    QPoint center(width() / 2,height() / 2);

    painter.translate(center);

    int rotute = (second % 60) * 6 - 180;

    int radius = width() / 2 - 15;

    painter.rotate(rotute);

    painter.drawLine(0,0,0,radius);

    painter.restore();
}

///
/// \brief WatchWidget::drawMinute 画分
///
void WatchWidget::drawMinute()
{

}

///
/// \brief WatchWidget::drawHour 画时针
///
void WatchWidget::drawHour()
{

}

///
/// \brief WatchWidget::paintEvent 画表
///
void WatchWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    /// 绘制背景
    painter.save();

    painter.setPen(QPen(QColor(255,255,255,255),1));

    painter.setBrush(QColor(255,255,255,125));

    QRectF rect(0,0,width(),width());

    painter.drawRoundedRect(rect,25,25);

    painter.restore();

    /// 绘制表盘
    painter.save();

    painter.setPen(QPen(QColor("#EEEEEE"),3));

    QPoint center(width() / 2, height() / 2);

    QPainterPath path;

    path.addEllipse(center, (width() / 2.0) - 10, (width() / 2.0) - 10);

    painter.setBrush(QColor("#FFFFFF"));

    painter.drawPath(path);

    painter.restore();

    /// 绘制表星
    painter.save();

    painter.setBrush(QColor("#000000"));

    painter.translate(center);

    // 半径
    int radius = width() / 2 - 10;

    for (int i = 0; i < 60; ++i) {

        if(i % 5 == 0){

            painter.setPen(QPen(QColor("#888888"),4));

            painter.drawLine(QPoint(0,radius), QPoint(0,radius - 15));

        }else{

            painter.setPen(QPen(QColor("#bababa"),2));

            painter.drawLine(QPoint(0,radius), QPoint(0,radius - 8));
        }

        painter.rotate(6.0);
    }

    painter.restore();

    /// 绘制表针的一个点
    painter.save();

    painter.setPen(QPen(QColor("#888888"),3));

    painter.setBrush(QColor("#888888"));

    QPainterPath pathCenter;

    pathCenter.addEllipse(center,3,3);

    painter.drawPath(pathCenter);

    painter.restore();

    /// 画秒针
    drawSecond(painter,QDateTime::currentSecsSinceEpoch());
}

///
/// \brief WatchWidget::showEvent 重写，保证是正方形
///
void WatchWidget::showEvent(QShowEvent *)
{
    resize(QSize(this->width(),this->width()));

}

void WatchWidget::mousePressEvent(QMouseEvent* e)
{
    if(e->button() == Qt::LeftButton){
        m_MousePress = true;
        m_PressPoint = e->globalPos() - this->pos();
    }
}

void WatchWidget::mouseReleaseEvent(QMouseEvent*)
{
    m_MousePress = false;
}

void WatchWidget::mouseMoveEvent(QMouseEvent *e)
{
    if(m_MousePress){
        QPoint point= e->globalPos() - m_PressPoint;
        this->move(point);
    }
}
