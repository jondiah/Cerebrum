#ifndef STARTUPVIEW_H
#define STARTUPVIEW_H

#include <QMainWindow>

namespace Ui {
class StartupView;
}

class StartupView : public QMainWindow
{
		Q_OBJECT

	public:
		explicit StartupView(QWidget *parent = 0);
		~StartupView();

	private:
		Ui::StartupView *ui;
};

#endif // STARTUPVIEW_H
