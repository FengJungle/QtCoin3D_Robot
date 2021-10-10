/********************************************************************************
** Form generated from reading UI file 'QtTestTransform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTTESTTRANSFORM_H
#define UI_QTTESTTRANSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtTestTransformClass
{
public:

    void setupUi(QWidget *QtTestTransformClass)
    {
        if (QtTestTransformClass->objectName().isEmpty())
            QtTestTransformClass->setObjectName(QStringLiteral("QtTestTransformClass"));
        QtTestTransformClass->resize(600, 400);

        retranslateUi(QtTestTransformClass);

        QMetaObject::connectSlotsByName(QtTestTransformClass);
    } // setupUi

    void retranslateUi(QWidget *QtTestTransformClass)
    {
        QtTestTransformClass->setWindowTitle(QApplication::translate("QtTestTransformClass", "QtTestTransform", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtTestTransformClass: public Ui_QtTestTransformClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTTESTTRANSFORM_H
