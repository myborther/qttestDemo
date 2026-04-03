#ifndef MARKDOWNTRANSFORM_H
#define MARKDOWNTRANSFORM_H

#include <QObject>

class MarkDownTransform : public QObject
{
    Q_OBJECT
public:
    explicit MarkDownTransform(QObject *parent = nullptr){};

    ///
    /// \brief markDownToText MD 转 Txt
    ///
    static bool markDownToText(QString mdPath, QString txtPath);
};

#endif // MARKDOWNTRANSFORM_H
