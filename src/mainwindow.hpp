#pragma once

#include <QMainWindow>
#include <QMenu>

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		MainWindow();

	private slots:
		void hello();

	private:
		void create_actions();
		void create_menus();

		QMenu *menu_file;
		QAction *action_hello;
};
