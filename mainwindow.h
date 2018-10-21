#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QPointer>

namespace Ui {
class MainWindow;
}

class DBHandler;
class Sell;
class AddItem;
class SellCount;

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

 private slots:
  void on_sellButton_clicked();
  void on_dataOutput_doubleClicked(const QModelIndex& index);
  void on_serachBox_textEdited(const QString& arg1);
  void on_addItems_clicked();
  void updateComboModel();
  void on_comboBox_currentTextChanged(const QString& arg1);

 public slots:
  void updateQuery();

 private:
  Ui::MainWindow* ui;
  QSqlQueryModel queryModel;
  QStringListModel spinnerModel;
  DBHandler* handler;
  Sell* sellWindow;
  AddItem* addItemWindow;
  SellCount* sellcount;
};

#endif  // MAINWINDOW_H
