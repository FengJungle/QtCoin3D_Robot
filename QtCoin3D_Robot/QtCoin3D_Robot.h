#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtCoin3D_Robot.h"

#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>

#include "Robot.h"

class QtCoin3D_Robot : public QMainWindow
{
	Q_OBJECT

public:
	QtCoin3D_Robot(QWidget *parent = Q_NULLPTR);
	~QtCoin3D_Robot();

	// Init UI robot axes
	void initUiRobotAxis();

public slots:

	// Set robot pose
	void setRobotPose();

private:
	Ui::QtCoin3D_RobotClass ui;

	// Coin root node
	SoSeparator* Coin_Root;

	// Robot root node
	SoSeparator* Robot_Root;

	// Robot
	Robot *robot;

	// Viewer
	SoQtExaminerViewer* simulatorView;
};
