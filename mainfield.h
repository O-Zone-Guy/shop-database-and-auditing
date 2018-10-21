#ifndef MAINFIELD_H
#define MAINFIELD_H

#include <QDialog>
#include <QList>
#include <QRadioButton>

namespace Ui {
class mainField;
}

class DBHandler;

class MainField : public QDialog {
  Q_OBJECT

 public:
  explicit MainField(DBHandler* handler, QWidget* parent = 0);
  ~MainField();

  void openthis(QString mainCat);

 private slots:
  void on_buttonBox_accepted();

 private:
  Ui::mainField* ui;
  DBHandler* handler;
  QString mainCat;
  QList<QRadioButton*> radioButtons;
};

#endif  // MAINFIELD_H
