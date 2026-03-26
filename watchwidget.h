#ifndef WATCHWIDGET_H
#define WATCHWIDGET_H

#include <QDebug>
#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class WatchWidget;
}

class WatchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WatchWidget(QWidget *parent = nullptr);
    ~WatchWidget();

protected:
    void paintEvent(QPaintEvent* e) override;
    void showEvent(QShowEvent* e) override;
    void mousePressEvent(QMouseEvent* e) override;
    void mouseReleaseEvent(QMouseEvent* e) override;
    void mouseMoveEvent(QMouseEvent* e) override;
private:
    Ui::WatchWidget *ui;

    bool m_MousePress = false;
    QPoint m_PressPoint;
};

#endif // WATCHWIDGET_H
