#include "QtTestTransform.h"
#include <QtDebug>

// Coin3D�е�Qt��
#include <Inventor/SoDB.h>
#include <Inventor/Qt/SoQt.h>

QtTestTransform::QtTestTransform(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	SoQt::init(ui.widget);

	root = nullptr;
	myView = nullptr;

	// �������ڵ�root
	root = new SoSeparator;
	root->ref();

	initScene();

	// ����viewer
	myView = new SoQtExaminerViewer(ui.widget);
	// ���ñ�����ɫ
	myView->setBackgroundColor(SbColor(0.2, 0.4, 0.4));
	myView->setSceneGraph(root);
	myView->viewAll();
	myView->show();

	// �źŲ�����
	connect(ui.lineEdit, SIGNAL(editingFinished()), this, SLOT(changeTransform1()));
	connect(ui.lineEdit_2_2, SIGNAL(editingFinished()), this, SLOT(changeTransform22()));
}

void QtTestTransform::initScene()
{
	// �����ο�������refCube,��������ӵ����ڵ�root�£�Ĭ��λ����ԭ�㴦�����ﲻ�ı�����
	refCube = new SoCube;
	root->addChild(refCube);
	refCube->height = 100;

	/**************************�Ӹ��ڵ�subRoot*****************************/
	// �����Ӹ��ڵ�subSep���˶�������Cube�ĸ��ڵ㣬����ӵ����ڵ�root��
	subRoot1 = new SoSeparator;
	subRoot1->ref();
	root->addChild(subRoot1);

	// ����λ�˱任�ڵ�trans1,��ӵ�subRoot1�£���Ϊ�˶�������cube1��λ�˱任�ڵ�
	// trans1�����õ�cube1��
	trans1 = new SoTransform;
	subRoot1->addChild(trans1);
	// ���ó�ʼλ��
	trans1->translation.setValue(100, 0, 0);

	// �����˶�������cube1����������ӵ��Ӹ��ڵ�subSep��
	cube1 = new SoCube;
	// ����cube1�ĳ����
	cube1->height = 10;
	cube1->width = 10;
	subRoot1->addChild(cube1);
	/**************************�Ӹ��ڵ�subRoot*****************************/

	trans21 = new SoTransform;
	trans21->translation.setValue(100, 50, 0);
	root->addChild(trans21);

	/**************************�Ӹ��ڵ�subRoo2t*****************************/
	// �����Ӹ��ڵ�subRoot2���˶�������Cube�ĸ��ڵ㣬����ӵ����ڵ�root��
	subRoot2 = new SoSeparator;
	subRoot2->ref();
	root->addChild(subRoot2);

	// ����λ�˱任�ڵ�trans22,��ӵ�subSep�£���Ϊ�˶�������cube��λ�˱任�ڵ�
	// trans22�����õ�cube2�ϣ���cube2��λ�ƽ���trans21��trans22���ۺ�
	trans22 = new SoTransform;
	subRoot2->addChild(trans22);

	// �����˶�������cube2����������ӵ��Ӹ��ڵ�subSep��
	cube2 = new SoCube;
	// ����cube2�ĳ����
	cube2->height = 20;
	cube2->width = 20;
	subRoot2->addChild(cube2);
	/**************************�Ӹ��ڵ�subRoot2*****************************/
	   
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
