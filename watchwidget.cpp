#include "watchwidget.h"
#include "ui_watchwidget.h"

#include <QGraphicsDropShadowEffect>
#include <QPainter>
#include <QPainterPath>

WatchWidget::WatchWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WatchWidget)
{
    ui->setupUi(this);

    // 无边框
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    // 透明
    setAttribute(Qt::WA_TranslucentBackground);

    // 边框
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(0);
    shadow->setColor(QColor(255,255,255,255));
    shadow->setBlurRadius(16);
    ui->mainWidget->setGraphicsEffect(shadow);
}

WatchWidget::~WatchWidget()
{
    delete ui;
}

///
/// \brief WatchWidget::paintEvent 画表
///
void WatchWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    painter.save();

    painter.setPen(QPen(QColor(200,200,200),3));

    QPoint center(width() / 2, height() / 2);

    QPainterPath path;

    path.addEllipse(center,
                    ( ui->mainWidget->width() / 2.0) - 10,
                    ( ui->mainWidget->height() / 2.0 ) - 10);

    painter.setBrush(QColor("#55FFFFFF"));

    painter.drawPath(path);

    painter.restore();
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
