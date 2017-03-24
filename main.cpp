#include "startupview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	StartupView w;
	w.show();

	return a.exec();
}
