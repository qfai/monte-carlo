#pragma once
#include<QtWidgets>
#include<QImage>
#include<QPixmap>
#include<QDebug>
#include"faitracer.h"
class FaiRender:public QWidget {
	Q_OBJECT
public:
	FaiRender(QWidget * parent) : QWidget(parent) {
		buffer = new QImage();
		/*if (!buffer->load("C:\\Users\\qfai\\Documents\\lena.png")) {
			qDebug() << "can't open image file" << endl;

		}*/
		label = new QLabel(this);
		//label->setGeometry(QRect(400, 30, 400, 23));
		
	}
	~FaiRender() {
		delete buffer;
		delete label;
	}
private:
	QImage* buffer;
	QPixmap mp;
	int width, height;
	QLabel* label;
	FaiTracer* tracer;
//public slots:

public:
	void saveimage() {
	QString fileName = QFileDialog::getOpenFileName(this, QObject::tr("save image file"), " ", QObject::tr("Allfile(*.*);;objfile(*.obj)"));
	qDebug() << fileName;
	buffer->save(fileName);
	}
	void setsample(int n) { tracer->setSampleCount(n); }
protected:
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
	
};