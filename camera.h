#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QCamera>

class Camera : public QObject
{
	Q_OBJECT
	public:
		Camera(QObject *parent);
		Camera(QObject *parent,
			   const QString devicename,
			   const QString description,
			   const bool isdefaultcamera);

		void setDeviceName(const QString devicename);
		void setDescription(const QString description);
		void setIsDefaultCamera(const bool isdefaultcamera);

		QString deviceName() { return m_deviceName; }
		QString description() { return m_description; }
		bool isDefaultCamera() { return m_isDefaultCamera; }

	signals:
		void deviceNameChanged(QString devicename);
		void descriptionChanged(QString description);
		void isDefaultCameraChanged(bool defaultcamera);

	private:
		QString m_deviceName;
		QString m_description;
		bool m_isDefaultCamera;
};

#endif // CAMERA_H
