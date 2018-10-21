#ifndef ADDITEM_H
#define ADDITEM_H

#include "dbhandler.h"
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QAbstractButton>

namespace Ui {
class AddItem;
}

class DBHandler;
class NewCat;

class AddItem : public QDialog {
  Q_OBJECT

 public:
  explicit AddItem(DBHandler* handler, QWidget* parent = 0);
  ~AddItem();
  void open(QString mainCat);
  void openEdit(QString mainCat, int id);

 private slots:
  void on_toolButton_clicked();
  void updateCombobox();
  void on_mainCats_currentTextChanged(const QString& arg1);
  void accepted();

 private:
  Ui::AddItem* ui;
  DBHandler* handler;
  QStringListModel* mainCatModel;
  NewCat* newCat;
  QList<QLabel*> fields;
  QList<QLineEdit*> values;
  bool edit = false;
  int idEdit;

 signals:
  void newCatAdded();
  void addedItem();
};

#endif  // ADDITEM_H
