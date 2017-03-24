#include "startupview.h"
#include "ui_startupview.h"

StartupView::StartupView(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::StartupView)
{
	ui->setupUi(this);

	QActionGroup *cameraDevicesGroup = new QActionGroup(this);
	cameraDevicesGroup->setExclusive(true);

	foreach (Camera *camera, m_cameraDevices.availableCameraList()) {
		QAction *cameraDeviceAction = new QAction(camera->description(), cameraDevicesGroup);
		cameraDeviceAction->setCheckable(true);
		cameraDeviceAction->setData(QVariant::fromValue(camera->description()));
		ui->menuCameras->addAction(cameraDeviceAction);
	}

	connect(cameraDevicesGroup, SIGNAL(triggered(QAction*)), SLOT(updateCameraDevice(QAction*)));
}

StartupView::~StartupView()
{
	delete ui;
}

void StartupView::updateCameraDevice(QAction *action)
{
	QString description = qvariant_cast<QString>(action->data());

	QByteArray devicename;
	QString temp = m_cameraDevices.availableCameraList().at(0)->deviceName();
	devicename = temp.toUtf8();

	qDebug() << "devicename: " << devicename;

	m_viewFinders.append(new QCameraViewfinder(ui->centralWidget));
	m_viewFinders.append(new QCameraViewfinder(ui->centralWidget));
	ui->gridLayout->addWidget(m_viewFinders.at(0));
	ui->gridLayout->addWidget(m_viewFinders.at(1));

	m_activeCameras.append(new QCamera(devicename,this));

	if(m_activeCameras.at(0) != NULL) {
		m_activeCameras.at(0)->setViewfinder(m_viewFinders.at(0));
		m_activeCameras.at(0)->setCaptureMode(QCamera::CaptureVideo);
		m_activeCameras.at(0)->start();
	}

	/*
	QString description = qvariant_cast<QString>(action->data());

	QByteArray devicename;
	QString temp = m_cameraDevices.availableCameraList().at(0)->deviceName();
	devicename = temp.toUtf8();

	qDebug() << "devicename: " << devicename;

	QCamera *qcamera = new QCamera(devicename,this);

	if(qcamera != NULL) {
		qcamera->setViewfinder(ui->viewfinder);
		qcamera->setCaptureMode(QCamera::CaptureVideo);
		qcamera->start();
	}
	*/
}


