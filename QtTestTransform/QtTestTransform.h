#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtTestTransform.h"

#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoCube.h>
#include <Inventor/nodes/SoTranslation.h>
#include <Inventor/nodes/SoTransform.h>

class QtTestTransform : public QWidget
{
    Q_OBJECT

public:
    QtTestTransform(QWidget *parent = Q_NULLPTR);
	~QtTestTransform();

	void initScene();

public slots:
	void changeTransform1();
	void changeTransform22();

private:
    Ui::QtTestTransformClass ui;

	// ¸ù½Úµã
	SoSeparator *root;
	SoSeparator *subRoot1;
	SoSeparator *subRoot2;
	// Viewer
	SoQtExaminerViewer* myView;

	SoCube* refCube;
	SoCube* cube1;
	SoCube* cube2;

	SoTransform* trans1;
	SoTransform* trans21;
	SoTransform* trans22;
};


