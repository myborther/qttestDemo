#include <QApplication>
#include <WatchWidget.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WatchWidget watch;

    watch.show();

    return a.exec();
}
