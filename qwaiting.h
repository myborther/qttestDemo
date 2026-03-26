#ifndef QWAITING_H
#define QWAITING_H

#include <QWidget>

namespace Ui {
class QWaiting;
}

class QWaiting : public QWidget
{
    Q_OBJECT

public:
    explicit QWaiting(QWidget *parent = nullptr);
    ~QWaiting();
    void playGIF();
    void stop();
protected:
    void showEvent(QShowEvent* e) override;
private:
    Ui::QWaiting *ui;
    QTimer *timer;
    int imgNum = 1;
};

#endif // QWAITING_H
