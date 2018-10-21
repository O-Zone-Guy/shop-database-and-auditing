#ifndef SELL_H
#define SELL_H

#include <QDialog>
#include <QDir>
#include <QTextStream>
#include <QFile>
#include <QFileInfo>
#include <QSpacerItem>

namespace Ui {
class sell;
}

class DBHandler;
class QLabel;

class Sell : public QDialog {
  Q_OBJECT

 public:
  explicit Sell(DBHandler* handler, QWidget* parent = 0);
  ~Sell();
  void sell(QString mainCat, int id);
  void reject();

 private slots:

  void on_buttonBox_accepted();

 private:
  // variables
  Ui::sell* ui;
  DBHandler* handler;
  QDir* mdir;
  QTextStream* stream;
  QFile* file;
  QFileInfo* fileInfo;

  QList<QLabel*> mainCats;
  QList<QLabel*> mainFields;
  QList<QLabel*> prices;
  QList<QLabel*> counts;
  QList<QLabel*> totals;
  QList<QSpacerItem*> vSpacer;
  QLabel* Total;

 public slots:
  void updateItems();

 signals:
  void sold();
};

#endif  // SELL_H
