/********************************************************************************
** Form generated from reading UI file 'mainfield.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFIELD_H
#define UI_MAINFIELD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_mainField
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *mainField)
    {
        if (mainField->objectName().isEmpty())
            mainField->setObjectName(QStringLiteral("mainField"));
        mainField->resize(400, 300);
        verticalLayout = new QVBoxLayout(mainField);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(mainField);
        groupBox->setObjectName(QStringLiteral("groupBox"));

        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(mainField);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(mainField);
        QObject::connect(buttonBox, SIGNAL(accepted()), mainField, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), mainField, SLOT(reject()));

        QMetaObject::connectSlotsByName(mainField);
    } // setupUi

    void retranslateUi(QDialog *mainField)
    {
        mainField->setWindowTitle(QApplication::translate("mainField", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("mainField", "Main Field:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mainField: public Ui_mainField {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFIELD_H
