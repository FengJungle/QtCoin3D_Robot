/********************************************************************************
** Form generated from reading UI file 'QtCoin3D_Robot.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCOIN3D_ROBOT_H
#define UI_QTCOIN3D_ROBOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtCoin3D_RobotClass
{
public:
    QWidget *centralWidget;
    QWidget *widget_Coin3D_Robot;
    QSlider *horizontalSlider_Axis1;
    QSlider *horizontalSlider_Axis2;
    QSlider *horizontalSlider_Axis3;
    QSlider *horizontalSlider_Axis4;
    QSlider *horizontalSlider_Axis5;
    QSlider *horizontalSlider_Axis6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtCoin3D_RobotClass)
    {
        if (QtCoin3D_RobotClass->objectName().isEmpty())
            QtCoin3D_RobotClass->setObjectName(QStringLiteral("QtCoin3D_RobotClass"));
        QtCoin3D_RobotClass->resize(678, 400);
        centralWidget = new QWidget(QtCoin3D_RobotClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget_Coin3D_Robot = new QWidget(centralWidget);
        widget_Coin3D_Robot->setObjectName(QStringLiteral("widget_Coin3D_Robot"));
        widget_Coin3D_Robot->setGeometry(QRect(10, 10, 411, 291));
        horizontalSlider_Axis1 = new QSlider(centralWidget);
        horizontalSlider_Axis1->setObjectName(QStringLiteral("horizontalSlider_Axis1"));
        horizontalSlider_Axis1->setGeometry(QRect(490, 20, 160, 19));
        horizontalSlider_Axis1->setOrientation(Qt::Horizontal);
        horizontalSlider_Axis2 = new QSlider(centralWidget);
        horizontalSlider_Axis2->setObjectName(QStringLiteral("horizontalSlider_Axis2"));
        horizontalSlider_Axis2->setGeometry(QRect(490, 50, 160, 19));
        horizontalSlider_Axis2->setOrientation(Qt::Horizontal);
        horizontalSlider_Axis3 = new QSlider(centralWidget);
        horizontalSlider_Axis3->setObjectName(QStringLiteral("horizontalSlider_Axis3"));
        horizontalSlider_Axis3->setGeometry(QRect(490, 80, 160, 19));
        horizontalSlider_Axis3->setOrientation(Qt::Horizontal);
        horizontalSlider_Axis4 = new QSlider(centralWidget);
        horizontalSlider_Axis4->setObjectName(QStringLiteral("horizontalSlider_Axis4"));
        horizontalSlider_Axis4->setGeometry(QRect(490, 110, 160, 19));
        horizontalSlider_Axis4->setOrientation(Qt::Horizontal);
        horizontalSlider_Axis5 = new QSlider(centralWidget);
        horizontalSlider_Axis5->setObjectName(QStringLiteral("horizontalSlider_Axis5"));
        horizontalSlider_Axis5->setGeometry(QRect(490, 140, 160, 19));
        horizontalSlider_Axis5->setOrientation(Qt::Horizontal);
        horizontalSlider_Axis6 = new QSlider(centralWidget);
        horizontalSlider_Axis6->setObjectName(QStringLiteral("horizontalSlider_Axis6"));
        horizontalSlider_Axis6->setGeometry(QRect(490, 170, 160, 19));
        horizontalSlider_Axis6->setOrientation(Qt::Horizontal);
        QtCoin3D_RobotClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtCoin3D_RobotClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 678, 23));
        QtCoin3D_RobotClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtCoin3D_RobotClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtCoin3D_RobotClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtCoin3D_RobotClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtCoin3D_RobotClass->setStatusBar(statusBar);

        retranslateUi(QtCoin3D_RobotClass);

        QMetaObject::connectSlotsByName(QtCoin3D_RobotClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtCoin3D_RobotClass)
    {
        QtCoin3D_RobotClass->setWindowTitle(QApplication::translate("QtCoin3D_RobotClass", "QtCoin3D_Robot", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtCoin3D_RobotClass: public Ui_QtCoin3D_RobotClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCOIN3D_ROBOT_H
