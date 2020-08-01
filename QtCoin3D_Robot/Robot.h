#ifndef _ROBOT_H
#define _ROBOT_H

#include "sodhtransform.h"

// Qt
#include <QFileDialog>
#include <QList>
#include <QKeyEvent>
#include <QtDebug>

// Coin3D中的Qt库
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

	// 设置DH参数
	void setDHParameters();

	// 初始化模型
	void initialRobot();

	// 打开模型
	SoVRMLGroup* openModel(QString fileName);

	void setAxis(double ip_joint[6]);
	void getAxis(double op_joint[6]);

	// 用户按键控制轴号
	int axisNum;

	SoSeparator* getRobotRootNode();

public slots:
	void getcurposition();

private:

	// 根节点
	SoSeparator *root;

	// 机器人节点
	SoSeparator *rootRobot;
	// 轴节点
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

	//*******建立DH模型以及逆解*******//
	// 轴杆参数：连杆长度
	double a1, a2, a3;

	// 轴杆参数：连杆偏置
	double d1, d4;

	// 存储六个关节值
	double xp_joint[6];
	double x, y, z, rx, ry, rz;

	// 关节范围
	double max_angle[6];
	double min_angle[6];
	int range[6];

	SoVRMLGroup *objectmodel;
};

#endif // _ROBOT_H
