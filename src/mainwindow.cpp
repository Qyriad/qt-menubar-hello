
#include <QMessageBox>
#include <QMenuBar>

#include "mainwindow.hpp"

MainWindow::MainWindow()
{
	this->action_hello = new QAction(tr("&Hello"), this);
	this->connect(this->action_hello, &QAction::triggered, this, &MainWindow::hello);

	// This line is not required on at least KDE.
	this->setMenuBar(new QMenuBar(nullptr));

	this->menu_file = this->menuBar()->addMenu(tr("&File"));
	this->menu_file->addAction(this->action_hello);

	this->setWindowTitle(tr("Menus"));
	this->setMinimumSize(160, 160);
	this->resize(480, 320);
}

void MainWindow::hello()
{
	QMessageBox::information(this, tr("Hello, title!"), tr("Hello, message!"));
}
