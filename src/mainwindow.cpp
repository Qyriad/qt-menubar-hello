#include <QMessageBox>
#include <QMenuBar>
#include <QFrame>

#include "mainwindow.hpp"

MainWindow::MainWindow()
{
	this->action_hello = new QAction(tr("&Hello"), this);
	// Not required for the menu bar and item to show up, but required for it to do anything.
	this->connect(this->action_hello, &QAction::triggered, this, &MainWindow::hello);

	// This is alluded to in the Qt documentation, but does not appear to be
	// necessary on either KDE or macOS.
	//this->setMenuBar(new QMenuBar(nullptr));

	this->menu_file = this->menuBar()->addMenu(tr("&File"));
	// Note: this takes ownership of `QAction action_hello`.
	this->menu_file->addAction(this->action_hello);
}

void MainWindow::hello()
{
	QMessageBox::information(this, tr("Hello, title!"), tr("Hello, message!"));
}

ChildWindow::ChildWindow(QWidget *parent) : QMainWindow(parent)
{
	// When this flag is set (and if this widget has a parent??), there are some extra requirements.
	this->setWindowFlags(Qt::Widget);

	// In a normal application presumably you'd set this flag in the parent's constructor,
	// but for demonstration purposes: if QMainWindow has a parent, *and* QMainWindow has the
	// Qt::Widget flag set, then QMainWindow's parent must have the Qt::Window flag set,
	// or the native menu bar will not show — and no menu bar will show at all unless you
	// setNativeMenuBar(false).
	dynamic_cast<QFrame *>(parent)->setWindowFlags(Qt::Window);

	this->action_hello = new QAction(tr("&Hello"), this);

	// We cannot use this->menuBar() here, and in fact if we setMenuBar(this->menu_bar), it will actually
	// break that menu bar.

	// The parent of this menu bar can be `this` on KDE, but not on macOS.
	this->menu_bar = new QMenuBar(nullptr);
	this->setMenuBar(this->menu_bar);
	this->menu_file = this->menuBar()->addMenu(tr("&File"));
	this->menu_file->addAction(this->action_hello);
}

void ChildWindow::hello()
{
	QMessageBox::information(this, tr("Hello, title!"), tr("Hello, message!"));
}
