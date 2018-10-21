/********************************************************************************
** Form generated from reading UI file 'sellcount.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELLCOUNT_H
#define UI_SELLCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_sellCount
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *id;
    QLabel *mainField;
    QLabel *price;
    QLabel *mainCat;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QSpinBox *spinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *sellCount)
    {
        if (sellCount->objectName().isEmpty())
            sellCount->setObjectName(QStringLiteral("sellCount"));
        sellCount->resize(184, 187);
        sellCount->setMinimumSize(QSize(184, 187));
        verticalLayout = new QVBoxLayout(sellCount);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        id = new QLabel(sellCount);
        id->setObjectName(QStringLiteral("id"));

        gridLayout->addWidget(id, 1, 0, 1, 1);

        mainField = new QLabel(sellCount);
        mainField->setObjectName(QStringLiteral("mainField"));

        gridLayout->addWidget(mainField, 1, 1, 1, 1);

        price = new QLabel(sellCount);
        price->setObjectName(QStringLiteral("price"));

        gridLayout->addWidget(price, 1, 2, 1, 1);

        mainCat = new QLabel(sellCount);
        mainCat->setObjectName(QStringLiteral("mainCat"));

        gridLayout->addWidget(mainCat, 0, 0, 1, 3, Qt::AlignHCenter);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        spinBox = new QSpinBox(sellCount);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(sellCount);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(sellCount);
        QObject::connect(buttonBox, SIGNAL(accepted()), sellCount, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), sellCount, SLOT(reject()));

        QMetaObject::connectSlotsByName(sellCount);
    } // setupUi

    void retranslateUi(QDialog *sellCount)
    {
        sellCount->setWindowTitle(QApplication::translate("sellCount", "Dialog", Q_NULLPTR));
        id->setText(QApplication::translate("sellCount", "TextLabel", Q_NULLPTR));
        mainField->setText(QApplication::translate("sellCount", "TextLabel", Q_NULLPTR));
        price->setText(QApplication::translate("sellCount", "TextLabel", Q_NULLPTR));
        mainCat->setText(QApplication::translate("sellCount", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class sellCount: public Ui_sellCount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELLCOUNT_H
