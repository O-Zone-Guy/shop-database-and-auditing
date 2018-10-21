/********************************************************************************
** Form generated from reading UI file 'sell.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELL_H
#define UI_SELL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_sell
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_2;
    QLabel *total;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_6;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *sell)
    {
        if (sell->objectName().isEmpty())
            sell->setObjectName(QStringLiteral("sell"));
        sell->resize(469, 385);
        sell->setMinimumSize(QSize(469, 291));
        verticalLayout = new QVBoxLayout(sell);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(sell);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(sell);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 3, 1, 1);

        label_6 = new QLabel(sell);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 8, 1, 1);

        label_4 = new QLabel(sell);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 4, 1, 1);

        label_5 = new QLabel(sell);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        label_3 = new QLabel(sell);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 6, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 7, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 5, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        total = new QLabel(sell);
        total->setObjectName(QStringLiteral("total"));

        gridLayout_2->addWidget(total, 0, 3, 1, 1);

        label_7 = new QLabel(sell);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(311, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        buttonBox = new QDialogButtonBox(sell);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(sell);
        QObject::connect(buttonBox, SIGNAL(accepted()), sell, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), sell, SLOT(reject()));

        QMetaObject::connectSlotsByName(sell);
    } // setupUi

    void retranslateUi(QDialog *sell)
    {
        sell->setWindowTitle(QApplication::translate("sell", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("sell", "Items to sell:", Q_NULLPTR));
        label_2->setText(QApplication::translate("sell", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Main Category</span></p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("sell", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Total</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("sell", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Price</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("sell", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Main Field</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("sell", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Count</span></p></body></html>", Q_NULLPTR));
        total->setText(QApplication::translate("sell", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; text-decoration: underline;\">Money</span></p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("sell", "Total:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class sell: public Ui_sell {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELL_H
