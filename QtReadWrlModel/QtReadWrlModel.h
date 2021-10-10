#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtReadWrlModel.h"

#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/nodes/SoSeparator.h>

class QtReadWrlModel : public QWidget
{
    Q_OBJECT

public:
    QtReadWrlModel(QWidget *parent = Q_NULLPTR);
	~QtReadWrlModel();

public slots:
	void openModel();

private:
    Ui::QtReadWrlModelClass ui;

	// root node
	SoSeparator* root;

	// Viewer
	SoQtExaminerViewer* myView;
};
