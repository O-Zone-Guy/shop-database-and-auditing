#ifndef SELSELLCOUNT_H
#define SELSELLCOUNT_H

#include <QDialog>

namespace Ui {
class selsellCount;
}

class DBHandler;

class selsellCount : public QDialog {
  Q_OBJECT

 public:
  explicit selsellCount(DBHandler* handler, QWidget* parent = 0);
  ~selsellCount();

 private:
  Ui::selsellCount* ui;
  DBHandler* handler;
};

#endif  // SELSELLCOUNT_H
