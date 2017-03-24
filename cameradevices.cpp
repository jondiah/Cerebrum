#include "cameradevices.h"

#include <QCameraInfo>

CameraDevices::CameraDevices(QObject *parent) :
	 QObject(parent)
{
	refreshAvailableCameras();
}

void CameraDevices::refreshAvailableCameras()
{
	QList<QCameraInfo> cameras = QCameraInfo::availableCameras();

	foreach (const QCameraInfo &cameraInfo, cameras) {
		addCamera(&cameraInfo);
	}

	qDebug() << "Cameras found: " << m_cameras.size();
	qDebug() << "Camera is: " << m_cameras.at(0)->description();
}

QList<Camera *> CameraDevices::availableCameraList()
{
	return m_cameras;
}

bool CameraDevices::addCamera(const QCameraInfo *newcamera)
{
	foreach (Camera *camera, m_cameras) {
		if(camera->deviceName() == newcamera->deviceName())
			return false;
	}

	qDebug() << "Add Camera: " << newcamera->description();

	m_cameras.append(new Camera(this,
								newcamera->deviceName(),
								newcamera->description(),
								false));

	return true;
}

