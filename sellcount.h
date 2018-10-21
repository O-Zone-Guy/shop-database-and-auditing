#ifndef SELLCOUNT_H
#define SELLCOUNT_H

#include <QDialog>
#include <QFile>

namespace Ui {
class sellCount;
}

class DBHandler;
class Sell;

class SellCount : public QDialog {
  Q_OBJECT

 public:
  explicit SellCount(Sell* sellWindow, DBHandler* handler, QWidget* parent = 0);
  ~SellCount();
  void getItem(QString mainCat, int id);

 private:
  Ui::sellCount* ui;
  DBHandler* handler;
  QFile fileReader;
  Sell* sellWindow;

 private slots:
  void accepted();

 signals:
  void addedItem();
};

#endif  // SELLCOUNT_H
