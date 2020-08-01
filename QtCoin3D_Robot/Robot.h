#ifndef _ROBOT_H
#define _ROBOT_H

#include "sodhtransform.h"

// Qt
#include <QFileDialog>
#include <QList>
#include <QKeyEvent>
#include <QtDebug>

// Coin3D�е�Qt��
#include <Inventor/SoDB.h>
#include <Inventor/Qt/SoQt.h>

// Coin3D
#include <Inventor/VRMLnodes/SoVRMLGroup.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoTransform.h>
#include <Inventor/actions/SoSearchAction.h>


#include <math.h>

#define PI 3.1415926535898 
#define em 0.0000000001
#define mmm 100000000
#define radianPerAngle  0.01745329251994333			//PI/180      
#define anglePerRadian  57.2957795130821975611		//180/PI

class Robot
{
public:
	Robot();
	~Robot();

	// ����DH����
	void setDHParameters();

	// ��ʼ��ģ��
	void initialRobot();

	// ��ģ��
	SoVRMLGroup* openModel(QString fileName);

	void setAxis(double ip_joint[6]);
	void getAxis(double op_joint[6]);

	// �û������������
	int axisNum;

	SoSeparator* getRobotRootNode();

public slots:
	void getcurposition();

private:

	// ���ڵ�
	SoSeparator *root;

	// �����˽ڵ�
	SoSeparator *rootRobot;
	// ��ڵ�
	SoSeparator
		*robotAxis0,
		*robotAxis1, *robotAxis2,
		*robotAxis3, *robotAxis4,
		*robotAxis5, *robotAxis6;
	SoSeparator * axisModel[7];
	QList<SoDHTransform *> angleAxises;
	SoDHTransform
		*angleAxis1, *angleAxis2,
		*angleAxis3, *angleAxis4,
		*angleAxis5, *angleAxis6;

	//*******����DHģ���Լ����*******//
	// ��˲��������˳���
	double a1, a2, a3;

	// ��˲���������ƫ��
	double d1, d4;

	// �洢�����ؽ�ֵ
	double xp_joint[6];
	double x, y, z, rx, ry, rz;

	// �ؽڷ�Χ
	double max_angle[6];
	double min_angle[6];
	int range[6];

	SoVRMLGroup *objectmodel;
};

#endif // _ROBOT_H
