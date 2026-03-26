#ifndef AUDIOINFO_H
#define AUDIOINFO_H

#include <QAudioFormat>
#include <QIODevice>
#include <QTcpSocket>
#include <QDebug>
#include <QFile>
#include <QPointer>
#include <QHostAddress>
/**
    参考Qt示例封装的音频输入设备
**/
class AudioInfo : public QIODevice
{
    struct WAVHeader {
        // RIFF 头部
        char riffChunkID[4] = {'R','I','F','F'};
        quint32 riffChunkSize = 0; // 后续填
        char format[4] = {'W','A','V','E'};
        // fmt 子块
        char fmtChunkID[4] = {'f','m','t',' '};
        quint32 fmtChunkSize = 16; // PCM 是 16
        quint16 audioFormat = 1;  // PCM = 1
        quint16 numChannels = 0;
        quint32 sampleRate = 0;
        quint32 byteRate = 0;
        quint16 blockAlign = 0;
        quint16 bitsPerSample = 0;
        // data 子块
        char dataChunkID[4] = {'d','a','t','a'};
        quint32 dataChunkSize = 0; // 后续填
    };

    Q_OBJECT
public:
    AudioInfo(const QAudioFormat &format);
    void start();
    void stop();
    qreal level() const { return m_level; }
    qint64 readData(char *data, qint64 maxlen) override;
    qint64 writeData(const char *data, qint64 len) override;
    void setOutputFile(const QString &filePath);
    void sendAudioToPhone(const char *data, qint64 len);
    void setLocalPort(quint16 port);
private:
    const QAudioFormat m_format;
    QFile m_outputFile; // 用于保存音频到文件
    quint32 m_maxAmplitude = 0;
    qreal m_level = 0.0; // 0.0 <= m_level <= 1.0

    int maxValue;
    WAVHeader m_wavHeader;
    QByteArray m_audioBuffer;
    void writeToWavHeader();   // 初始写入 WAV 头部
    void updateWavHeader();   // 录音结束时更新 WAV 头部大小

    // TCP
    QPointer<QTcpSocket> mAudioSocket = nullptr;
    quint16 localPort;
signals:
    void update();
};

#endif // AUDIOINFO_H
