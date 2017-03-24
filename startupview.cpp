#include "startupview.h"
#include "ui_startupview.h"

StartupView::StartupView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartupView)
{
	ui->setupUi(this);
}

StartupView::~StartupView()
{
	delete ui;
}
