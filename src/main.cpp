#include <iostream>
#include <string>

#include <QApplication>
#include <QFrame>

#include "mainwindow.hpp"

int main(int argc, char *argv[])
{
	QApplication qapp(argc, argv);

	if (argc > 1) {
		std::string arg1(argv[1]);
		if (arg1 == "--child") {
			QFrame frame;
			ChildWindow wind_main(&frame);
			wind_main.setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);
			wind_main.show();
			return qapp.exec();
		} else {
			std::cout << "pass --child for the child window example; otherwise pass no arguments\n";
			return 1;
		}
	} else {
		MainWindow wind_main;
		wind_main.show();
		return qapp.exec();
	}

	return -1; // impossible
}
