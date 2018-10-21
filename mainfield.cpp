#include "mainfield.h"
#include "ui_mainfield.h"
#include "dbhandler.h"
#include <QMap>
#include <QRadioButton>
#include <QVBoxLayout>

MainField::MainField(DBHandler* handler, QWidget* parent)
    : QDialog(parent), ui(new Ui::mainField), handler(handler) {
  ui->setupUi(this);
  connect(this, SIGNAL(accepted()), this, SLOT(on_buttonBox_accepted()));
}

MainField::~MainField() {
  delete ui;
}

void MainField::openthis(QString mainCat) {
  // init mainCat
  this->mainCat = mainCat;

  // get fields
  QMap<QString, QVariant::Type> fields = handler->getTableDetails(mainCat);

  QVBoxLayout* vLayout = new QVBoxLayout;

  // adds radio buttons
  for (int i = 0; i < fields.keys().size(); i++) {
    radioButtons.append(new QRadioButton(fields.keys().at(i), this));
    vLayout->addWidget(radioButtons.at(i));
  }

  // checks first button to avoid no selection error
  radioButtons.at(0)->setChecked(true);

  // set up vLayput and sets layout
  vLayout->addStretch(1);
  ui->groupBox->setLayout(vLayout);
  open();
}

void MainField::on_buttonBox_accepted() {
  QString field;

  // gets selected button text
  for (QRadioButton* button : radioButtons) {
    if (button->isChecked()) {
      field = button->text();
      break;
    }
  }

  // set MianField
  handler->setMainField(mainCat, field);
}
