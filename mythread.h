#pragma once

#include <QThread>
#include <QTimer>
#include <QDebug>

class MyThread  : public QThread
{
	Q_OBJECT

public:
	MyThread(QObject *parent = nullptr);
	~MyThread();

protected:
	void run() override;

private:
	QTimer* testTimer = nullptr;
	int speed = 0;
};

