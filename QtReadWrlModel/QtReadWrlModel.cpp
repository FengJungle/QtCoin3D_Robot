#include "QtReadWrlModel.h"

// Qt
#include <QFileDialog>
#include <QList>
#include <QtDebug>

// Coin3D中的Qt库
#include <Inventor/SoDB.h>
#include <Inventor/Qt/SoQt.h>

// Coin3D
#include <Inventor/VRMLnodes/SoVRMLGroup.h>
#include <Inventor/nodes/SoTransform.h>
#include <Inventor/actions/SoSearchAction.h>

QtReadWrlModel::QtReadWrlModel(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	SoQt::init(ui.widget);

	root = nullptr;
	myView = nullptr;

	// 创建根节点root
	root = new SoSeparator;
	root->ref();

	// 创建viewer
	myView = new SoQtExaminerViewer(ui.widget);
	// 设置背景颜色
	myView->setBackgroundColor(SbColor(0.2,0.4,0.4));
	myView->setSceneGraph(root);
	myView->viewAll();
	myView->show();

	// 信号槽连接：鼠标点击“打开”，选择模型文件
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(openModel()));
}

QtReadWrlModel::~QtReadWrlModel()
{
	if (root) {
		root->unref();
	}
	if (myView) {
		delete myView;
		myView = nullptr;
	}
}


void QtReadWrlModel::openModel()
{
	QString fileName = QFileDialog::getOpenFileName(
		this,
		tr("Open File"),
		"",
		"",
		0);
	if (!fileName.isNull())
	{
		ui.lineEdit->setText(fileName);
		// fileName是文件名
		SoInput myInput;
		SoSearchAction search;
		search.setType(SoVRMLGroup::getClassTypeId());
		search.setInterest(SoSearchAction::FIRST);
		search.apply(root);

		// 打开wrl文件
		if (!myInput.openFile(fileName.toStdString().data()));
		SoVRMLGroup *objectModel = SoDB::readAllVRML(&myInput);
		int numOfChildren = objectModel->getNumChildren();
		qDebug() << "number of children: " << numOfChildren << endl;
		root->addChild(objectModel);
		myView->viewAll();
	}
	else {
		// 取消
	}
}

