#ifndef DBHANDLER_H
#define DBHANDLER_H

#include <QApplication>
#include <QDateTime>
#include <QDir>
#include <QObject>
#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql>
#include <QMap>
#include "mainwindow.h"

class MainWindow;

class DBHandler : public QObject {
  Q_OBJECT

 public:
  DBHandler(MainWindow* mWindow);

  bool addMainItem(QString name,
                   QStringList fieldNames,
                   QStringList fieldTypes);
  bool addItem(QString mainCat, QStringList fields, QStringList values);
  bool sellItem(QString mainCat, int id, int amount);
  QStringList getAllMainCat();
  QMap<QString, QVariant::Type> getTableDetails(QString mainCat);
  QMap<QString, QString> getItem(QString cat, int id);
  void setMainField(QString mainCat, QString field);
  QString getMainField(QString MainCat);
  void open();
  void close() { db.close(); }
  void updateItem(QString mainCat,
                  int id,
                  QStringList fields,
                  QStringList values);
  QSqlDatabase getDB() { return db; }

  // tables and fields names
  QString TABLE_MAIN;
  QString COLUMN_ID;
  QString COLUMN_MAIN_NAME;

 public slots:

 private:
  QSqlDatabase db;
  QDir databaseloc;
  QString dbName = "inventory";
  QString path;
  QSqlQuery query;
};

#endif  // DBHANDLER_H
