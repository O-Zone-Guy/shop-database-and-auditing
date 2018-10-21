#include "additem.h"
#include "ui_additem.h"
#include "dbhandler.h"
#include <QStringListModel>
#include "newcat.h"
#include "mainfield.h"

AddItem::AddItem(DBHandler* handler, QWidget* parent)
    : QDialog(parent),
      ui(new Ui::AddItem),
      handler(handler),
      newCat(new NewCat(handler, this)) {
  ui->setupUi(this);

  // connect statements
  connect(newCat, SIGNAL(newCatAdded()), this, SLOT(updateCombobox()));
  connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accepted()));
}

AddItem::~AddItem() {
  delete ui;
}

void AddItem::open(QString mainCat) {
  // set up var
  edit = false;

  // set up combobox
  mainCatModel = new QStringListModel(handler->getAllMainCat(), this);
  ui->mainCats->setModel(mainCatModel);
  ui->mainCats->setEnabled(true);

  // get field names and types
  QMap<QString, QVariant::Type> field = handler->getTableDetails(mainCat);

  fields.clear();
  values.clear();

  // empty formLayout
  for (int i = ui->formLayout->count() - 1; i >= 0; i--) {
    ui->formLayout->removeRow(i);
  }

  // populate formLayout
  for (int i = 0; i < field.size(); i++) {
    if (field.keys().at(i) != "id") {
      fields.append(new QLabel(field.keys().at(i), this));
      values.append(new QLineEdit(this));
    }
  }
  // set validators for fields
  for (int i = 0; i < fields.size(); i++) {
    if (field.values().at(i) == QVariant::Type::Int) {
      values.at(i)->setValidator(new QDoubleValidator(0, 1000000000, 2, this));
    } else if (field.values().at(i) == QVariant::Type::Int) {
      values.at(i)->setValidator(new QIntValidator(0, 1000000000, this));
    }
    ui->formLayout->addRow(fields.at(i), values.at(i));
  }

  exec();
}

// edit item, gets item and inserts text in fields
void AddItem::openEdit(QString mainCat, int id) {
  // init vars
  edit = true;
  idEdit = id;

  // set up combobox
  mainCatModel = new QStringListModel(handler->getAllMainCat(), this);
  ui->mainCats->setModel(mainCatModel);

  // set up cur text and disablinh combobox
  ui->mainCats->setCurrentText(mainCat);
  ui->mainCats->setEnabled(false);

  // disabling adding new Cat
  ui->toolButton->setEnabled(false);

  // get field names and types
  QMap<QString, QVariant::Type> field = handler->getTableDetails(mainCat);

  fields.clear();
  values.clear();

  // empty formLayout
  for (int i = ui->formLayout->count() - 1; i >= 0; i--) {
    ui->formLayout->removeRow(i);
  }

  // populate formLayout
  for (int i = 0; i < field.size(); i++) {
    if (field.keys().at(i) != "id") {
      fields.append(new QLabel(field.keys().at(i), this));
      values.append(new QLineEdit(this));
    }
  }

  // set validators for fields
  for (int i = 0; i < fields.size(); i++) {
    if (field.values().at(i) == QVariant::Type::Double) {
      values.at(i)->setValidator(new QDoubleValidator(0, 1000000000, 2, this));
    } else if (field.values().at(i) == QVariant::Type::Int) {
      values.at(i)->setValidator(new QIntValidator(0, 1000000000, this));
    }
    ui->formLayout->addRow(fields.at(i), values.at(i));
  }

  // get item from db
  QMap<QString, QString> item = handler->getItem(mainCat, id);

  // populate fields with data
  int j = 0;
  for (int i = 0; i < item.size(); i++) {
    if (item.keys().at(i) == "id")
      j++;
    else
      values.at(i - j)->setText(item.values().at(i));
  }

  exec();
}

void AddItem::on_toolButton_clicked() {
  newCat->showAdd();
}

void AddItem::updateCombobox() {
  mainCatModel->setStringList(handler->getAllMainCat());
  emit newCatAdded();
}

void AddItem::on_mainCats_currentTextChanged(const QString& arg1) {
  QMap<QString, QVariant::Type> field = handler->getTableDetails(arg1);

  fields.clear();
  values.clear();

  // empty formLayout
  for (int i = ui->formLayout->rowCount() - 1; i >= 0; i--) {
    ui->formLayout->removeRow(i);
  }

  // populate formLayout
  for (int i = 0; i < field.size(); i++) {
    fields.append(new QLabel(field.keys().at(i), this));
    values.append(new QLineEdit(this));
    if (field.values().at(i) == QVariant::Type::Double) {
      values.at(i)->setValidator(new QDoubleValidator(0, 1000000000, 2, this));
    } else if (field.values().at(i) == QVariant::Type::Int) {
      values.at(i)->setValidator(new QIntValidator(0, 1000000000, this));
    }
    if (field.keys().at(i) != "id") {
      ui->formLayout->addRow(fields.at(i), values.at(i));
    }
  }
}

void AddItem::accepted() {
  QStringList fieldsString;
  QStringList valuesString;

  for (int i = 0; i < fields.size(); i++) {
    fieldsString.append(fields.at(i)->text());
    valuesString.append(values.at(i)->text());
  }

  // add item
  if (!edit)
    handler->addItem(ui->mainCats->currentText(), fieldsString, valuesString);

  // edit item
  else
    handler->updateItem(ui->mainCats->currentText(), idEdit, fieldsString,
                        valuesString);
  // emit to update table
  emit addedItem();
}
