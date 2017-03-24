#ifndef CAMERAHANDLER_H
#define CAMERAHANDLER_H

#include <QObject>

class CameraHandler : public QObject
{
		Q_OBJECT
	public:
		explicit CameraHandler(QObject *parent = 0);

	signals:

	public slots:
};

#endif // CAMERAHANDLER_H
