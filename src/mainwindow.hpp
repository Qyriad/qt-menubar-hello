#pragma once

#include <QMainWindow>
#include <QMenu>
#include <QAction>

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

		// These are not required to be class fields.
		QMenu *menu_file;
		QAction *action_hello;
};
