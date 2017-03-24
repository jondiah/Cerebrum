#include "camera.h"

Camera::Camera(QObject *parent) :
	QObject(parent)
{
	setDeviceName("");
	setDescription("");
	setIsDefaultCamera(false);
}

Camera::Camera(QObject *parent,
			   const QString devicename,
			   const QString description,
			   const bool isdefaultcamera) :
	QObject(parent)
{
	setDeviceName(devicename);
	setDescription(description);
	setIsDefaultCamera(isdefaultcamera);
}

void Camera::setDeviceName(const QString devicename)
{
	if(devicename == m_deviceName)
		return;

	m_deviceName = devicename;
	emit deviceNameChanged(m_deviceName);
}

void Camera::setDescription(const QString description)
{
	if(description == m_description)
		return;

	m_description = description;
	emit descriptionChanged(m_description);
}

void Camera::setIsDefaultCamera(const bool isdefaultcamera)
{
	if(isdefaultcamera == m_isDefaultCamera)
		return;

	m_isDefaultCamera = isdefaultcamera;
	emit isDefaultCameraChanged(m_isDefaultCamera);
}
