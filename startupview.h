#ifndef STARTUPVIEW_H
#define STARTUPVIEW_H

#include <QMainWindow>
#include <QCameraViewfinder>
#include <QCamera>

#include "cameradevices.h"
#include "camerahandler.h"

namespace Ui {
class StartupView;
}

class StartupView : public QMainWindow
{
		Q_OBJECT

	public:
		explicit StartupView(QWidget *parent = 0);
		~StartupView();

	public slots:
		void updateCameraDevice(QAction *action);

	private:
		Ui::StartupView *ui;
		CameraDevices m_cameraDevices;

		QList<QCamera*> m_activeCameras;
		QList<QCameraViewfinder*> m_viewFinders;
};

#endif // STARTUPVIEW_H
