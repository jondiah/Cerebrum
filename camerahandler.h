#ifndef CAMERAHANDLER_H
#define CAMERAHANDLER_H

#include <QObject>
#include <QCamera>

class CameraHandler : public QObject
{
		Q_OBJECT
	public:
		explicit CameraHandler(QObject *parent = 0);

	signals:

	public slots:

	private:
		QList<QCamera*> m_activeCameras;
};

#endif // CAMERAHANDLER_H
