#include"fairender.h"
#include<QLabel>
void FaiRender::paintEvent(QPaintEvent *event) {
	tracer->rayTrace(buffer);
	mp = mp.fromImage(*buffer);
	//QLabel* label = new QLabel(this);
	label->setPixmap(mp);
	label->adjustSize();
	label->show();
	this->show();
}