#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
   setupUi(this);
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::changesamplemethod()
{
}

void MainWindow::readobj()
{
}

void MainWindow::setsamplecount()
{
	centralWidget->setsample(dig->textEdit->text().toInt());
	qDebug() << dig->textEdit->text() << endl;
	//dig->textEdit->text();
}

void MainWindow::about()
{
	qDebug() << "about";
	QMessageBox message(QMessageBox::NoIcon, "About", "This is Rendered by Monter Carlor Ray Tracing algorithm and wrapped by QT widget\\ Done by Qfai ", QMessageBox::Yes, NULL);
	if (message.exec() == QMessageBox::Yes)
	{
	}
}

void MainWindow::showdig()
{

}

