#include <iostream>

#include <QApplication>

#include "mainwindow.hpp"

int main(int argc, char *argv[])
{
	QApplication qapp(argc, argv);

	MainWindow wind_main;
	wind_main.show();

	return qapp.exec();
}
