#include "markdowntransform.h"

#include <QDebug>
#include <QTextDocument>
#include <QTextStream>
#include <QFile>
#include <QTextCodec>

bool MarkDownTransform::markDownToText(QString mdPath,QString txtPath)
{
    // 1. 读取 Markdown 文件
    QFile mdFile(mdPath);
    if (!mdFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "无法打开 Markdown 文件:" << mdPath;
        return false;
    }
    QTextStream in(&mdFile);
    // 建议设置 UTF-8 编码，防止中文乱码
    in.setCodec(QTextCodec::codecForLocale());
    QString mdContent = in.readAll();
    mdFile.close();
    // 2. 利用 QTextDocument 解析 Markdown
    QTextDocument doc;
    doc.setMarkdown(mdContent);
    // 3. 导出为纯文本
    QString plainText = doc.toPlainText();
    // 4. 写入 TXT 文件
    QFile txtFile(txtPath);
    if (!txtFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "无法创建目标 TXT 文件:" << txtPath;
        return false;
    }
    QTextStream out(&txtFile);
    out.setCodec(QTextCodec::codecForLocale());
    out << plainText;
    txtFile.close();
    return true;
}
