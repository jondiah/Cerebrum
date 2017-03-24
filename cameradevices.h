#ifndef CAMERADEVICES_H
#define CAMERADEVICES_H

#include "camera.h"

#include <QObject>
#include <QCameraInfo>

class CameraDevices : public QObject
{
	public:
		CameraDevices(QObject *parent = NULL);

		void refreshAvailableCameras();
		QList<Camera *> availableCameraList();

	private:
		bool addCamera(const QCameraInfo *newcamera);

		QList<Camera*> m_cameras;
};

#endif // CAMERADEVICES_H
