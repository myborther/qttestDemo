#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAudioDeviceInfo>
#include <QMainWindow>
#include <QDebug>
#include <QAudioInput>
#include <AudioInfo.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
//private slots:
//    void startAudio();
//    void stopAudio();
private:
    Ui::MainWindow *ui;
    QAudioDeviceInfo m_AudioDeviceInfo;
    QScopedPointer<AudioInfo> m_audioInfo;
    QScopedPointer<QAudioInput> m_audioInput;
};
#endif // MAINWINDOW_H
