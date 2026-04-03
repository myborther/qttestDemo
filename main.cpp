#include <MarkDownTransform.h>
#include <QApplication>
#include <WatchWidget.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // WatchWidget watch;

    // watch.show();

    MarkDownTransform::markDownToText(R"(C:\Users\admin\Downloads\md.md)",R"(C:\Users\admin\Downloads\md.txt)");

    return a.exec();
}
