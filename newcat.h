#ifndef NEWCAT_H
#define NEWCAT_H

#include <QDialog>
#include <QComboBox>
#include <QLineEdit>
#include <QStringListModel>
namespace Ui {
class NewCat;
}

class DBHandler;
class MainField;

class NewCat : public QDialog {
  Q_OBJECT

 public:
  explicit NewCat(DBHandler* handler, QWidget* parent = 0);
  ~NewCat();

  void showAdd();

 private slots:
  void on_newField_clicked();
  void addNewCat();

 private:
  Ui::NewCat* ui;
  DBHandler* handler;
  QList<QLineEdit*> fieldNames;
  QList<QComboBox*> fieldType;
  QStringList fieldList;
  QStringListModel* fieldsModel;
  MainField* mainField;

 signals:
  void newCatAdded();

  // TODO add QStringListModel with all needed field types
};

#endif  // NEWCAT_H
