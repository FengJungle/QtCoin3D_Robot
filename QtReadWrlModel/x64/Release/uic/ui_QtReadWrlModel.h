/********************************************************************************
** Form generated from reading UI file 'QtReadWrlModel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTREADWRLMODEL_H
#define UI_QTREADWRLMODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtReadWrlModelClass
{
public:

    void setupUi(QWidget *QtReadWrlModelClass)
    {
        if (QtReadWrlModelClass->objectName().isEmpty())
            QtReadWrlModelClass->setObjectName(QStringLiteral("QtReadWrlModelClass"));
        QtReadWrlModelClass->resize(600, 400);

        retranslateUi(QtReadWrlModelClass);

        QMetaObject::connectSlotsByName(QtReadWrlModelClass);
    } // setupUi

    void retranslateUi(QWidget *QtReadWrlModelClass)
    {
        QtReadWrlModelClass->setWindowTitle(QApplication::translate("QtReadWrlModelClass", "QtReadWrlModel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtReadWrlModelClass: public Ui_QtReadWrlModelClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTREADWRLMODEL_H
