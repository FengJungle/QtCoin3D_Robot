#include "Robot.h"

Robot::Robot()
{
	initialRobot();
}

Robot::~Robot()
{

}

void Robot::initialRobot()
{
	rootRobot = new SoSeparator;
	robotAxis0 = new SoSeparator;
	robotAxis1 = new SoSeparator;
	robotAxis2 = new SoSeparator;
	robotAxis3 = new SoSeparator;
	robotAxis4 = new SoSeparator;
	robotAxis5 = new SoSeparator;
	robotAxis6 = new SoSeparator;

	robotAxis0->setName("机器人0轴");
	robotAxis1->setName("机器人1轴");
	robotAxis2->setName("机器人2轴");
	robotAxis3->setName("机器人3轴");
	robotAxis4->setName("机器人4轴");
	robotAxis5->setName("机器人5轴");
	robotAxis6->setName("机器人6轴");

	angleAxis1 = new SoDHTransform;
	angleAxis2 = new SoDHTransform;
	angleAxis3 = new SoDHTransform;
	angleAxis4 = new SoDHTransform;
	angleAxis5 = new SoDHTransform;
	angleAxis6 = new SoDHTransform;
	angleAxises.append(angleAxis1);
	angleAxises.append(angleAxis2);
	angleAxises.append(angleAxis3);
	angleAxises.append(angleAxis4);
	angleAxises.append(angleAxis5);
	angleAxises.append(angleAxis6);
	angleAxis1->setName("机器人1轴DH变换");
	angleAxis2->setName("机器人2轴DH变换");
	angleAxis3->setName("机器人3轴DH变换");
	angleAxis4->setName("机器人4轴DH变换");
	angleAxis5->setName("机器人5轴DH变换");
	angleAxis6->setName("机器人6轴DH变换");

	setDHParameters();

	axisModel[0] = new SoSeparator;
	axisModel[1] = new SoSeparator;
	axisModel[2] = new SoSeparator;
	axisModel[3] = new SoSeparator;
	axisModel[4] = new SoSeparator;
	axisModel[5] = new SoSeparator;
	axisModel[6] = new SoSeparator;

	axisModel[1]->addChild(angleAxis1->inverseMatrix());

	axisModel[2]->addChild(angleAxis2->inverseMatrix());
	axisModel[2]->addChild(angleAxis1->inverseMatrix());

	axisModel[3]->addChild(angleAxis3->inverseMatrix());
	axisModel[3]->addChild(angleAxis2->inverseMatrix());
	axisModel[3]->addChild(angleAxis1->inverseMatrix());

	axisModel[4]->addChild(angleAxis4->inverseMatrix());
	axisModel[4]->addChild(angleAxis3->inverseMatrix());
	axisModel[4]->addChild(angleAxis2->inverseMatrix());
	axisModel[4]->addChild(angleAxis1->inverseMatrix());

	axisModel[5]->addChild(angleAxis5->inverseMatrix());
	axisModel[5]->addChild(angleAxis4->inverseMatrix());
	axisModel[5]->addChild(angleAxis3->inverseMatrix());
	axisModel[5]->addChild(angleAxis2->inverseMatrix());
	axisModel[5]->addChild(angleAxis1->inverseMatrix());

	axisModel[6]->addChild(angleAxis6->inverseMatrix());
	axisModel[6]->addChild(angleAxis5->inverseMatrix());
	axisModel[6]->addChild(angleAxis4->inverseMatrix());
	axisModel[6]->addChild(angleAxis3->inverseMatrix());
	axisModel[6]->addChild(angleAxis2->inverseMatrix());
	axisModel[6]->addChild(angleAxis1->inverseMatrix());

	SoTransform *scaler = new SoTransform;
	scaler->scaleFactor.setValue(1000, 1000, 1000);

	for (int i = 0; i <= 6; i++)
	{
		QString path("Resources/Robot/ER3A-C60/ER3A-C60-" + QString::number(i + 1) + ".wrl");
		SoVRMLGroup *robotModel = openModel(path);
		if (robotModel != NULL)
		{
			SoSeparator *robotModelSep = (SoSeparator *)robotModel->getChild(0);
			axisModel[i]->addChild((SoSeparator *)robotModelSep);
		}
		robotModel->unref();
	}

	robotAxis0->addChild(axisModel[0]);
	robotAxis1->addChild(axisModel[1]);
	robotAxis2->addChild(axisModel[2]);
	robotAxis3->addChild(axisModel[3]);
	robotAxis4->addChild(axisModel[4]);
	robotAxis5->addChild(axisModel[5]);
	robotAxis6->addChild(axisModel[6]);

	rootRobot->addChild(robotAxis0);
	robotAxis0->addChild(angleAxis1);
	robotAxis0->addChild(robotAxis1);
	robotAxis1->addChild(angleAxis2);
	robotAxis1->addChild(robotAxis2);
	robotAxis2->addChild(angleAxis3);
	robotAxis2->addChild(robotAxis3);
	robotAxis3->addChild(angleAxis4);
	robotAxis3->addChild(robotAxis4);
	robotAxis4->addChild(angleAxis5);
	robotAxis4->addChild(robotAxis5);
	robotAxis5->addChild(angleAxis6);
	robotAxis5->addChild(robotAxis6);
}

SoSeparator* Robot::getRobotRootNode()
{
	return this->rootRobot;
}

void Robot::setDHParameters()
{
	a1 = 50;
	a2 = 270;
	a3 = 70;                    
	d1 = 321.5;
	d4 = 299;
	angleAxis1->init( 0.0,   d1,   0.0,  0.0);
	angleAxis2->init(90.0,  0.0,  90.0,   a1);
	angleAxis3->init( 0.0,  0.0,   0.0,   a2);
	angleAxis4->init( 0.0,   d4,  90.0,   a3);
	angleAxis5->init( 0.0,  0.0, -90.0,  0.0);
	angleAxis6->init( 0.0,  0.0,  90.0,  0.0);
}

SoVRMLGroup * Robot::openModel(QString fileName)
{
	SoInput * myInput = new SoInput;
	if (myInput->openFile(fileName.toStdString().data()))
	{
		SoVRMLGroup *model = SoDB::readAllVRML(myInput);
		myInput->closeFile();
		delete myInput;
		return model;
	}
	myInput->closeFile();
	delete myInput;
	return NULL;
}

void Robot::setAxis(double ip_joint[6])
{
	angleAxis1->rotateTheta(ip_joint[0]);
	angleAxis2->rotateTheta(ip_joint[1]);
	angleAxis3->rotateTheta(ip_joint[2]);
	angleAxis4->rotateTheta(ip_joint[3]);
	angleAxis5->rotateTheta(ip_joint[4]);
	angleAxis6->rotateTheta(ip_joint[5]);
	for (int i = 0; i < 6; i++) {
		xp_joint[i] = ip_joint[i];
	}

	rootRobot->touch();
}

void Robot::getAxis(double op_joint[6])
{
	op_joint[0] = angleAxis1->getValue();
	op_joint[1] = angleAxis2->getValue();
	op_joint[2] = angleAxis3->getValue();
	op_joint[3] = angleAxis4->getValue();
	op_joint[4] = angleAxis5->getValue();
	op_joint[5] = angleAxis6->getValue();
	for (int i = 0; i < 6; i++) {
		xp_joint[i] = op_joint[i];
	}
}