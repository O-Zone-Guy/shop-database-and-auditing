#include "newcat.h"
#include "ui_newcat.h"
#include "dbhandler.h"
#include <QLineEdit>
#include <QComboBox>
#include <QMessageBox>
#include "mainfield.h"

NewCat::NewCat(DBHandler* handler, QWidget* parent)
    : QDialog(parent),
      ui(new Ui::NewCat),
      handler(handler),
      fieldsModel(new QStringListModel(this)),
      mainField(new MainField(handler, this)) {
  ui->setupUi(this);
  fieldList.append("Number");
  fieldList.append("Diecemal");
  fieldList.append("Text");
  fieldList.append("True/False");
  fieldList.append("Date");
  fieldsModel->setStringList(fieldList);

  connect(this, SIGNAL(accepted()), this, SLOT(addNewCat()));
}

NewCat::~NewCat() {
  delete ui;
}

void NewCat::showAdd() {
  // reset formLayout
  for (int i = 0; i < ui->newFields->rowCount(); i++) {
    ui->newFields->removeRow(i);
  }

  // clear lists
  fieldNames.clear();
  fieldType.clear();

  show();
}

// button clicked
void NewCat::on_newField_clicked() {
  // add new field
  fieldNames.append(new QLineEdit(this));
  fieldType.append(new QComboBox(this));

  // set up field type
  fieldType.at(fieldType.size() - 1)->setModel(fieldsModel);

  // add widgets to form
  ui->newFields->addRow(fieldNames.at(fieldNames.size() - 1),
                        fieldType.at(fieldType.size() - 1));
}

void NewCat::addNewCat() {
  QStringList names;
  QStringList type;

  // set up fieldType list
  for (int i = 0; i < fieldType.size(); i++) {
    switch (fieldList.indexOf(fieldType.at(i)->currentText())) {
      case 0:
        type.append("INTEGER");
        break;
      case 1:
        type.append("DOUBLE");
        break;
      case 2:
        type.append("TEXT");
        break;
      case 3:
        type.append("TINYINT(1)");
        break;
      case 4:
        type.append("date");
      default:
        break;
    }
  }

  // get field names
  for (QLineEdit* text : fieldNames) {
    names.append(text->text());
  }

  // exec and check
  if (!handler->addMainItem(ui->name->text(), names, type)) {  // fail

    // message box
    QMessageBox::StandardButton reply;
    reply = QMessageBox::warning(this, "Add new Category",
                                 "Adding Category Failed");
    if (reply == QMessageBox::Ok) {  // do something maybe?
    }
  } else {                                  // success
    emit newCatAdded();                     // update lists
    mainField->openthis(ui->name->text());  // choose mainField
  }
}
