#include "mainwindow.h"

#include <QApplication>
#include <QWaiting.h>
#include <mythread.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // MyThread* thread = new MyThread;
    // thread->start();
    // QEventLoop loop;
    // QWaiting waiting;
    // waiting.show();
    // loop.exec();

    return a.exec();
}
