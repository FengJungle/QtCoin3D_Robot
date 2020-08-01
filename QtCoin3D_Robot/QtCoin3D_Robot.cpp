#include "QtCoin3D_Robot.h"

#include <Inventor/Qt/SoQt.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>

QtCoin3D_Robot::QtCoin3D_Robot(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	SoQt::init(ui.widget_Coin3D_Robot);

	Coin_Root = new SoSeparator();
	Coin_Root->ref(); 

	// init robot
	robot = new Robot();
	Robot_Root = robot->getRobotRootNode();
	Coin_Root->addChild(Robot_Root);
	initUiRobotAxis();


	simulatorView = new SoQtExaminerViewer(ui.widget_Coin3D_Robot);
	simulatorView->setSceneGraph(Coin_Root);
	simulatorView->setBackgroundColor(SbColor(0.60, 0.77, 0.43));
	simulatorView->show();
	SoQt::show(ui.widget_Coin3D_Robot);
}

QtCoin3D_Robot::~QtCoin3D_Robot()
{
	if (robot != NULL) {
		delete robot;
	}
}

void QtCoin3D_Robot::initUiRobotAxis()
{
	this->ui.horizontalSlider_Axis1->setRange(-18500, 18500);
	this->ui.horizontalSlider_Axis2->setRange(-3500, 15500);
	this->ui.horizontalSlider_Axis3->setRange(-13000, 15400);
	this->ui.horizontalSlider_Axis4->setRange(-35000, 35000);
	this->ui.horizontalSlider_Axis5->setRange(-13000, 13000);
	this->ui.horizontalSlider_Axis6->setRange(-35000, 35000);

	connect(ui.horizontalSlider_Axis1, SIGNAL(valueChanged(int)), this, SLOT(setRobotPose()));
	connect(ui.horizontalSlider_Axis2, SIGNAL(valueChanged(int)), this, SLOT(setRobotPose()));
	connect(ui.horizontalSlider_Axis3, SIGNAL(valueChanged(int)), this, SLOT(setRobotPose()));
	connect(ui.horizontalSlider_Axis4, SIGNAL(valueChanged(int)), this, SLOT(setRobotPose()));
	connect(ui.horizontalSlider_Axis5, SIGNAL(valueChanged(int)), this, SLOT(setRobotPose()));
	connect(ui.horizontalSlider_Axis6, SIGNAL(valueChanged(int)), this, SLOT(setRobotPose()));

	ui.horizontalSlider_Axis2->setValue(9000);
}

void QtCoin3D_Robot::setRobotPose()
{
	double input_Joint[6] = { 0,0,0,0,0,0 };
	input_Joint[0] = 0.01*ui.horizontalSlider_Axis1->value();
	input_Joint[1] = 0.01*ui.horizontalSlider_Axis2->value();
	input_Joint[2] = 0.01*ui.horizontalSlider_Axis3->value();
	input_Joint[3] = 0.01*ui.horizontalSlider_Axis4->value();
	input_Joint[4] = 0.01*ui.horizontalSlider_Axis5->value();
	input_Joint[5] = 0.01*ui.horizontalSlider_Axis6->value();

	ui.lineEdit_Axis1->setText(QString::number(input_Joint[0]));
	ui.lineEdit_Axis2->setText(QString::number(input_Joint[1]));
	ui.lineEdit_Axis3->setText(QString::number(input_Joint[2]));
	ui.lineEdit_Axis4->setText(QString::number(input_Joint[3]));
	ui.lineEdit_Axis5->setText(QString::number(input_Joint[4]));
	ui.lineEdit_Axis6->setText(QString::number(input_Joint[5]));

	this->robot->setAxis(input_Joint);
}
