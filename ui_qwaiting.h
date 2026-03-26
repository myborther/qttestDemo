/********************************************************************************
** Form generated from reading UI file 'qwaiting.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWAITING_H
#define UI_QWAITING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QWaiting
{
public:
    QGridLayout *gridLayout;
    QWidget *mainWidget;
    QGridLayout *gridLayout_2;
    QLabel *moveLabel;

    void setupUi(QWidget *QWaiting)
    {
        if (QWaiting->objectName().isEmpty())
            QWaiting->setObjectName(QString::fromUtf8("QWaiting"));
        QWaiting->setWindowModality(Qt::ApplicationModal);
        QWaiting->resize(100, 100);
        QWaiting->setMinimumSize(QSize(100, 100));
        QWaiting->setMaximumSize(QSize(100, 100));
        QWaiting->setAutoFillBackground(false);
        QWaiting->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(QWaiting);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(6, 6, 6, 6);
        mainWidget = new QWidget(QWaiting);
        mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
        mainWidget->setMinimumSize(QSize(88, 88));
        mainWidget->setMaximumSize(QSize(88, 88));
        mainWidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(mainWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(3, 3, 3, 3);
        moveLabel = new QLabel(mainWidget);
        moveLabel->setObjectName(QString::fromUtf8("moveLabel"));
        moveLabel->setMinimumSize(QSize(60, 60));
        moveLabel->setMaximumSize(QSize(60, 60));
        QFont font;
        font.setPointSize(12);
        moveLabel->setFont(font);
        moveLabel->setScaledContents(true);
        moveLabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(moveLabel, 0, 0, 1, 1);


        gridLayout->addWidget(mainWidget, 0, 0, 1, 1);


        retranslateUi(QWaiting);

        QMetaObject::connectSlotsByName(QWaiting);
    } // setupUi

    void retranslateUi(QWidget *QWaiting)
    {
        QWaiting->setWindowTitle(QString());
        moveLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QWaiting: public Ui_QWaiting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWAITING_H
