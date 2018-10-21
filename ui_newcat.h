/********************************************************************************
** Form generated from reading UI file 'newcat.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWCAT_H
#define UI_NEWCAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewCat
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QLineEdit *name;
    QSpacerItem *horizontalSpacer;
    QPushButton *newField;
    QFormLayout *formLayout_2;
    QLabel *label_5;
    QLabel *label_6;
    QFormLayout *newFields;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewCat)
    {
        if (NewCat->objectName().isEmpty())
            NewCat->setObjectName(QStringLiteral("NewCat"));
        NewCat->resize(400, 300);
        verticalLayout = new QVBoxLayout(NewCat);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_7 = new QLabel(NewCat);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout->addWidget(label_7);

        name = new QLineEdit(NewCat);
        name->setObjectName(QStringLiteral("name"));

        horizontalLayout->addWidget(name);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        newField = new QPushButton(NewCat);
        newField->setObjectName(QStringLiteral("newField"));

        horizontalLayout->addWidget(newField);


        verticalLayout->addLayout(horizontalLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_5 = new QLabel(NewCat);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(NewCat);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, label_6);


        verticalLayout->addLayout(formLayout_2);

        newFields = new QFormLayout();
        newFields->setObjectName(QStringLiteral("newFields"));

        verticalLayout->addLayout(newFields);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        label = new QLabel(NewCat);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        label_3 = new QLabel(NewCat);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::FieldRole, label_3);

        label_2 = new QLabel(NewCat);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label_4 = new QLabel(NewCat);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::FieldRole, label_4);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(NewCat);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(NewCat);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewCat, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewCat, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewCat);
    } // setupUi

    void retranslateUi(QDialog *NewCat)
    {
        NewCat->setWindowTitle(QApplication::translate("NewCat", "Dialog", Q_NULLPTR));
        label_7->setText(QApplication::translate("NewCat", "Category Name:", Q_NULLPTR));
        newField->setText(QApplication::translate("NewCat", "Add new", Q_NULLPTR));
        label_5->setText(QApplication::translate("NewCat", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Field Name</span></p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("NewCat", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Type</span></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("NewCat", "Quantity:", Q_NULLPTR));
        label_3->setText(QApplication::translate("NewCat", "Integer", Q_NULLPTR));
        label_2->setText(QApplication::translate("NewCat", "Price:", Q_NULLPTR));
        label_4->setText(QApplication::translate("NewCat", "Currency", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewCat: public Ui_NewCat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCAT_H
