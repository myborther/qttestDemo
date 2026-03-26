#include "qwaiting.h"
#include "ui_qwaiting.h"

#include <MainWindow.h>
#include <QGraphicsDropShadowEffect>
#include <QIcon>
#include <QTimer>

QWaiting::QWaiting(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QWaiting)
{
    ui->setupUi(this);


    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(0,1);
    shadow->setColor(QColor(0,36,80,80));
    shadow->setBlurRadius(10);
    ui->mainWidget->setGraphicsEffect(shadow);

    timer = new QTimer();
    connect(timer,&QTimer::timeout,this,&QWaiting::playGIF);
    timer->start(50);
}

QWaiting::~QWaiting()
{
    timer->stop();
    timer->deleteLater();
    delete ui;
}

void QWaiting::playGIF()
{
    int i = this->imgNum % 50;
    QString url = ":/image/gif/%1.png";
    QIcon icon(url.arg(i));
    ui->moveLabel->setPixmap(icon.pixmap(500,500));
    ui->moveLabel->setScaledContents(true);
    this->imgNum++;
    return;
}

void QWaiting::stop()
{
    timer->stop();
}

void QWaiting::showEvent(QShowEvent *e)
{
    this->setAttribute(Qt::WA_Mapped);
    QWidget::showEvent(e);
}
