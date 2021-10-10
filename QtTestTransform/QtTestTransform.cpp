#include "QtTestTransform.h"
#include <QtDebug>

// Coin3D中的Qt库
#include <Inventor/SoDB.h>
#include <Inventor/Qt/SoQt.h>

QtTestTransform::QtTestTransform(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	SoQt::init(ui.widget);

	root = nullptr;
	myView = nullptr;

	// 创建根节点root
	root = new SoSeparator;
	root->ref();

	initScene();

	// 创建viewer
	myView = new SoQtExaminerViewer(ui.widget);
	// 设置背景颜色
	myView->setBackgroundColor(SbColor(0.2, 0.4, 0.4));
	myView->setSceneGraph(root);
	myView->viewAll();
	myView->show();

	// 信号槽连接
	connect(ui.lineEdit, SIGNAL(editingFinished()), this, SLOT(changeTransform1()));
	connect(ui.lineEdit_2_2, SIGNAL(editingFinished()), this, SLOT(changeTransform22()));
}

void QtTestTransform::initScene()
{
	// 创建参考立方体refCube,并将其添加到根节点root下（默认位置在原点处，这里不改变它）
	refCube = new SoCube;
	root->addChild(refCube);
	refCube->height = 100;

	/**************************子根节点subRoot*****************************/
	// 创建子根节点subSep，运动立方体Cube的根节点，并添加到根节点root下
	subRoot1 = new SoSeparator;
	subRoot1->ref();
	root->addChild(subRoot1);

	// 创建位姿变换节点trans1,添加到subRoot1下，作为运动立方体cube1的位姿变换节点
	// trans1将作用到cube1上
	trans1 = new SoTransform;
	subRoot1->addChild(trans1);
	// 设置初始位置
	trans1->translation.setValue(100, 0, 0);

	// 创建运动立方体cube1，并将其添加到子根节点subSep下
	cube1 = new SoCube;
	// 设置cube1的长宽高
	cube1->height = 10;
	cube1->width = 10;
	subRoot1->addChild(cube1);
	/**************************子根节点subRoot*****************************/

	trans21 = new SoTransform;
	trans21->translation.setValue(100, 50, 0);
	root->addChild(trans21);

	/**************************子根节点subRoo2t*****************************/
	// 创建子根节点subRoot2，运动立方体Cube的根节点，并添加到根节点root下
	subRoot2 = new SoSeparator;
	subRoot2->ref();
	root->addChild(subRoot2);

	// 创建位姿变换节点trans22,添加到subSep下，作为运动立方体cube的位姿变换节点
	// trans22将作用到cube2上，但cube2的位移将是trans21和trans22的综合
	trans22 = new SoTransform;
	subRoot2->addChild(trans22);

	// 创建运动立方体cube2，并将其添加到子根节点subSep下
	cube2 = new SoCube;
	// 设置cube2的长宽高
	cube2->height = 20;
	cube2->width = 20;
	subRoot2->addChild(cube2);
	/**************************子根节点subRoot2*****************************/
	   
}

QtTestTransform::~QtTestTransform()
{
	if (root) {
		root->unref();
	}
	if (myView) {
		delete myView;
		myView = nullptr;
	}
}

void QtTestTransform::changeTransform1()
{
	QString text1 = ui.lineEdit->text();
	qDebug() << text1 << endl;

	int pos = text1.toInt();
	trans1->translation.setValue(pos, 0, 0);
}

void QtTestTransform::changeTransform22()
{
	QString text22 = ui.lineEdit_2_2->text();
	qDebug() << text22 << endl;

	int pos = text22.toInt();
	trans22->translation.setValue(pos, 0, 0);
}
