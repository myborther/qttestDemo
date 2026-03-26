#include "mainwindow.h"
#include "selfbutton.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SelfButton* selfButton = new SelfButton(this);
    ui->gridLayout->addWidget(selfButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::startAudio()
//{
//    m_AudioDeviceInfo = ui->audioInDeviceComboBox->currentData().value<QAudioDeviceInfo>();
//
//    QAudioFormat format;
//    format.setSampleRate(16000);
//    format.setChannelCount(1);
//    format.setSampleSize(16);
//    format.setSampleType(QAudioFormat::SignedInt);
//    format.setByteOrder(QAudioFormat::LittleEndian);
//    format.setCodec("audio/pcm");
//
//    if (m_AudioDeviceInfo.isFormatSupported(format)) {
//        qDebug() << "Supported Audio";
//    }else{
//        qDebug() << "No Supported Audio";
//        return;
//    }
//
//
//    m_audioInfo.reset(new AudioInfo(format));
//    m_audioInfo->setLocalPort(11111);
//    // m_audioInfo->setOutputFile(R"(C:\Users\admin\Pictures\output\output.wav)");
//    connect(m_audioInfo.data(), &AudioInfo::update, [&]() {
//        ui->progressBar->setValue(m_audioInfo->level() * 100);
//    });
//    m_audioInfo->start();
//    m_audioInput.reset(new QAudioInput(m_AudioDeviceInfo, format));
//    m_audioInput->start(m_audioInfo.data());
//}
//
//void MainWindow::stopAudio()
//{
//    m_audioInfo->stop();
//    m_audioInput->stop();
//}
