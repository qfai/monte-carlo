#pragma once
#include"obj.h"
#include<QString>
#include<QImage>
class FaiTracer {
private:
	enum Sample_method{Monte_Carlo, Stratiffed,stiff} sample_method;
	int sample_count;
	Scene* m_s;
	//maybe camera
	//need to have width and weight info
public:
	void castray();
	bool loadScene(QString filename);
	bool setSample_method(int n);//the enum order
	bool setSampleCount(int n) { sample_count = n; return true; }
	void rayTrace(QImage* img);
//public slots:

};