#include "audioinfo.h"
#include "qendian.h"

AudioInfo::AudioInfo(const QAudioFormat &format)
    : m_format(format)
{
    switch (m_format.sampleSize()) {
    case 8:
        switch (m_format.sampleType()) {
        case QAudioFormat::UnSignedInt:
            m_maxAmplitude = 255;
            break;
        case QAudioFormat::SignedInt:
            m_maxAmplitude = 127;
            break;
        default:
            break;
        }
        break;
    case 16:
        switch (m_format.sampleType()) {
        case QAudioFormat::UnSignedInt:
            m_maxAmplitude = 65535;
            break;
        case QAudioFormat::SignedInt:
            m_maxAmplitude = 32767;
            break;
        default:
            break;
        }
        break;
    case 32:
        switch (m_format.sampleType()) {
        case QAudioFormat::UnSignedInt:
            m_maxAmplitude = 0xffffffff;
            break;
        case QAudioFormat::SignedInt:
            m_maxAmplitude = 0x7fffffff;
            break;
        case QAudioFormat::Float:
            m_maxAmplitude = 0x7fffffff; // Kind of
        default:
            break;
        }
        break;
    default:
        break;
    }
    mAudioSocket = new QTcpSocket(this);
}

void AudioInfo::start()
{
    // 设置 WAV 头部参数
    m_wavHeader.numChannels = m_format.channelCount();
    m_wavHeader.sampleRate = m_format.sampleRate();
    m_wavHeader.bitsPerSample = m_format.sampleSize();
    m_wavHeader.byteRate = m_format.sampleRate() * m_format.channelCount() * (m_format.sampleSize() / 8);
    m_wavHeader.blockAlign = m_format.channelCount() * (m_format.sampleSize() / 8);
    sendAudioToPhone(reinterpret_cast<char*>(&m_wavHeader), sizeof(WAVHeader));
    open(QIODevice::WriteOnly);
}

void AudioInfo::stop()
{
    close();
    if (m_outputFile.isOpen()) {
        //updateWavHeader();
        m_outputFile.close();
    }
    if(mAudioSocket){
        mAudioSocket->close();
        mAudioSocket->deleteLater();
    }
}

qint64 AudioInfo::readData(char *data, qint64 maxlen)
{
    Q_UNUSED(data)
    Q_UNUSED(maxlen)

    return 0;
}

qint64 AudioInfo::writeData(const char *data, qint64 len)
{
    if (m_maxAmplitude) {

    }

    if (m_outputFile.isOpen() && data && len > 0) {
        m_outputFile.write(data, len);
    }

    if(mAudioSocket){
        sendAudioToPhone(data, len);
    }

    emit update();
    return len;
}

void AudioInfo::setOutputFile(const QString &filePath)
{
    if (m_outputFile.isOpen()) {
        m_outputFile.close();
    }
    m_outputFile.setFileName(filePath);
    if (!m_outputFile.open(QIODevice::WriteOnly)) {
        qDebug() << "Failed to open file for writing:" << filePath;
    }

    // 设置 WAV 头部参数
    m_wavHeader.numChannels = m_format.channelCount();
    m_wavHeader.sampleRate = m_format.sampleRate();
    m_wavHeader.bitsPerSample = m_format.sampleSize();
    m_wavHeader.byteRate = m_format.sampleRate() * m_format.channelCount() * (m_format.sampleSize() / 8);
    m_wavHeader.blockAlign = m_format.channelCount() * (m_format.sampleSize() / 8);
    writeToWavHeader();
}

void AudioInfo::sendAudioToPhone(const char *data, qint64 len)
{
    if(mAudioSocket){
        if(mAudioSocket->state() != QTcpSocket::ConnectedState){
            mAudioSocket->connectToHost(QHostAddress::LocalHost,localPort,OpenModeFlag::WriteOnly);
            mAudioSocket->waitForBytesWritten(3000);
            if(mAudioSocket->state() == QTcpSocket::ConnectedState){
                mAudioSocket->write(data,len);
            }else{
                QString error = mAudioSocket->errorString();
            }
        }else{
            mAudioSocket->write(data,len);
        }
    }
}

void AudioInfo::setLocalPort(quint16 port)
{
    localPort = port;
}

void AudioInfo::writeToWavHeader()
{
    m_wavHeader.riffChunkSize = 36;
    m_wavHeader.dataChunkSize = 0;
    m_outputFile.seek(0);
    m_outputFile.write(reinterpret_cast<char*>(&m_wavHeader), sizeof(WAVHeader));
}

void AudioInfo::updateWavHeader()
{
    m_wavHeader.riffChunkSize = 36 + m_outputFile.size(); // uint32(4) + uint32(4) + uint32(4)
    m_wavHeader.dataChunkSize = m_outputFile.size() - sizeof(WAVHeader);
    m_outputFile.seek(0);
    m_outputFile.write(reinterpret_cast<char*>(&m_wavHeader), sizeof(WAVHeader));
}
