#include <QMessageBox>
#include <QMenuBar>

#include "mainwindow.hpp"

MainWindow::MainWindow()
{
	this->action_hello = new QAction(tr("&Hello"), this);
	this->connect(this->action_hello, &QAction::triggered, this, &MainWindow::hello);

	// This is alluded to in the Qt documentation, but does not appear to be
	// necessary on either KDE or macOS.
	//this->setMenuBar(new QMenuBar(nullptr));

	this->menu_file = this->menuBar()->addMenu(tr("&File"));
	this->menu_file->addAction(this->action_hello);
}

void MainWindow::hello()
{
	QMessageBox::information(this, tr("Hello, title!"), tr("Hello, message!"));
}
