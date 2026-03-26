#include "mythread.h"
#include <QEventLoop>

#include <windows.h>
#include <timeapi.h>

MyThread::MyThread(QObject *parent)
	: QThread(parent)
{

	testTimer = new QTimer(this);

	connect(testTimer, &QTimer::timeout, this, [=] {	
		qDebug() << speed;
		speed = 0;
	});

	connect(this, &QThread::started, this, [=]() {	
		testTimer->start(1000);
	});
}

MyThread::~MyThread()
{}

void MyThread::run()
{

	while (1) {
        msleep(1); // ms
		speed++;
	}
}

