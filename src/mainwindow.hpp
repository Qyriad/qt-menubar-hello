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
		// These are not required to be class fields.
		QMenu *menu_file;
		QAction *action_hello;
};

// Additional example to demonstrate some edge cases.
class ChildWindow : public QMainWindow
{
	Q_OBJECT

	public:
		ChildWindow(QWidget *parent);

	private slots:
		void hello();

	private:
		QMenuBar *menu_bar;
		QMenu *menu_file;
		QAction *action_hello;
};
