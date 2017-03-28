#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include"fairender.h"
#include"inputdialog.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
	
public slots:
void setsamplecount();
	void changesamplemethod();
	void readobj();
	void about();
	void showdig();
	void saveimage() {
		centralWidget->saveimage();
	}
public:
	InputDialog* dig;
	QAction* actionSaveImage;
	QAction *actionRead_obj;
	QAction *actionExample1;
	QAction *actionExample2;
	QAction *actionSampling_count;
	QAction *actionAbout;
	QAction *actionRandom;
	QAction *actionBlue_noise;
	FaiRender *centralWidget;
	QMenuBar *menuBar;
	QMenu *menuFile;
	QMenu *menuSampling;
	QMenu *menuSampling_method;
	QMenu *menuAbout;
	QToolBar *mainToolBar;
	QStatusBar *statusBar;

	void setupUi(QMainWindow *MainWindow)
	{
		if (MainWindow->objectName().isEmpty())
			MainWindow->setObjectName(QStringLiteral("MainWindow"));
		MainWindow->resize(900, 600);
		actionRead_obj = new QAction(MainWindow);
		actionRead_obj->setObjectName(QStringLiteral("actionRead_obj"));
		actionExample1 = new QAction(MainWindow);
		actionExample1->setObjectName(QStringLiteral("actionExample1"));
		actionExample2 = new QAction(MainWindow);
		actionExample2->setObjectName(QStringLiteral("actionExample2"));
		actionSaveImage = new QAction(MainWindow);
		actionSaveImage->setObjectName(QStringLiteral("actionSaveImage"));
		actionSampling_count = new QAction(MainWindow);
		actionSampling_count->setObjectName(QStringLiteral("actionSampling_count"));
		actionAbout = new QAction(MainWindow);
		actionAbout->setObjectName(QStringLiteral("actionAbout"));
		actionRandom = new QAction(MainWindow);
		actionRandom->setObjectName(QStringLiteral("actionRandom"));
		actionRandom->setCheckable(true);
		actionBlue_noise = new QAction(MainWindow);
		actionBlue_noise->setObjectName(QStringLiteral("actionBlue_noise"));
		actionBlue_noise->setCheckable(true);
		centralWidget = new FaiRender(MainWindow);
		centralWidget->setObjectName(QStringLiteral("centralWidget"));
		MainWindow->setCentralWidget(centralWidget);
		menuBar = new QMenuBar(MainWindow);
		menuBar->setObjectName(QStringLiteral("menuBar"));
		menuBar->setGeometry(QRect(0, 0, 400, 23));
		menuFile = new QMenu(menuBar);
		menuFile->setObjectName(QStringLiteral("menuFile"));
		menuSampling = new QMenu(menuBar);
		menuSampling->setObjectName(QStringLiteral("menuSampling"));
		menuSampling_method = new QMenu(menuSampling);
		menuSampling_method->setObjectName(QStringLiteral("menuSampling_method"));
		menuAbout = new QMenu(menuBar);
		menuAbout->setObjectName(QStringLiteral("menuAbout"));
		MainWindow->setMenuBar(menuBar);
		mainToolBar = new QToolBar(MainWindow);
		mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
		MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
		statusBar = new QStatusBar(MainWindow);
		statusBar->setObjectName(QStringLiteral("statusBar"));
		MainWindow->setStatusBar(statusBar);

		menuBar->addAction(menuFile->menuAction());
		menuBar->addAction(menuSampling->menuAction());
		menuBar->addAction(menuAbout->menuAction());
		menuFile->addAction(actionRead_obj);
		menuFile->addAction(actionExample1);
		menuFile->addAction(actionExample2);
		menuFile->addAction(actionSaveImage);
		menuSampling->addAction(menuSampling_method->menuAction());
		menuSampling->addAction(actionSampling_count);
		menuSampling_method->addAction(actionRandom);
		menuSampling_method->addAction(actionBlue_noise);
		menuAbout->addAction(actionAbout);
		dig = new InputDialog();
		dig->visible(false);
		retranslateUi(MainWindow);
		connect(actionSampling_count, SIGNAL(trigger()), MainWindow, SLOT(showdig()));
		// connect(dig, SIGNAL(dig->accepted), MainWindow, SLOT(setsamplecount());
		connect(actionAbout, SIGNAL(trigger()), MainWindow, SLOT(about()));
		connect(actionSaveImage, SIGNAL(trigger()),MainWindow, SLOT(saveimage()));
	} // setupUi

	void retranslateUi(QMainWindow *MainWindow)
	{
		MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
		actionRead_obj->setText(QApplication::translate("MainWindow", "read obj", 0));
		actionExample1->setText(QApplication::translate("MainWindow", "Example1", 0));
		actionExample2->setText(QApplication::translate("MainWindow", "Example2", 0));
		actionSaveImage->setText(QApplication::translate("MainWindow", "SaveImage", 0));
		actionSampling_count->setText(QApplication::translate("MainWindow", "Sampling count", 0));
		actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
		actionRandom->setText(QApplication::translate("MainWindow", "Random", 0));
		actionBlue_noise->setText(QApplication::translate("MainWindow", "Blue noise", 0));
		menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
		menuSampling->setTitle(QApplication::translate("MainWindow", "Sampling", 0));
		menuSampling_method->setTitle(QApplication::translate("MainWindow", "Sampling method", 0));
		menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0));
	} // retranslateUi

};

#endif // MAINWINDOW_H
