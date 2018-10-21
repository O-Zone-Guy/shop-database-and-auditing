#include "dbhandler.h"
#include <QApplication>
#include <QDateTime>
#include <QFileInfo>
#include <QMessageBox>
#include <QStringList>
#include <QtSql/QSqlDatabase>
#include <iostream>
#include "mainwindow.h"

using namespace std;

DBHandler::DBHandler(MainWindow* mWindow) {
  // init vars
  path = databaseloc.currentPath() + "/database";
  TABLE_MAIN = "main_table";
  COLUMN_ID = "_id";
  COLUMN_MAIN_NAME = "main_name";

  // check if dir exits
  QFileInfo fileInfo(path);
  if (!fileInfo.exists()) {
    if (databaseloc.mkpath(path)) {
      mWindow->close();
    }
  }

  // db name and loc
  path += "/" + dbName + ".db";

  // add db
  db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName(path);

  // open test, sets up query and creates mainTable if not exists
  if (db.open()) {
    query = QSqlQuery(db);
    query.exec("CREATE TABLE IF NOT EXISTS " + TABLE_MAIN + "(" + COLUMN_ID +
               " INTEGER PRIMARY KEY AUTOINCREMENT, " + COLUMN_MAIN_NAME +
               " TEXT, mainField TEXT);");

  } else {
    // stop programme from continueing
    QMessageBox::StandardButton reply;

    reply = QMessageBox::warning(
        mWindow, "Error",
        "Was not able to open database file.\n" + db.lastError().text());

    if (reply == QMessageBox::Ok) {
      // exits with error
      exit(1);
    }
  }
}

bool DBHandler::sellItem(QString mainCat, int id, int amount) {
  db.open();

  // exec and check if successful
  if (!query.exec("SELECT count FROM " + mainCat + " WHERE id =" +
                  QString::number(id))) {
    qDebug() << query.lastError();
    qDebug() << query.lastQuery();

    // if failed return false
    return false;
  }
  // get count
  query.first();
  // init count
  int count = query.value(0).toInt();

  // deducting sold count
  count -= amount;

  if (query.exec("UPDATE " + mainCat + " SET Count = " +
                 QString::number(count) + " WHERE id = " + QString::number(id)))
    return true;
  else {
    qDebug() << query.lastError();
    qDebug() << query.lastQuery();
    return false;
  }
}

QStringList DBHandler::getAllMainCat() {
  QStringList list;

  db.open();

  // exec and check if successful
  if (query.exec("SELECT " + COLUMN_MAIN_NAME + " FROM " + TABLE_MAIN +
                 " WHERE 1")) {
    // check if list of mainCats is empty
    if (query.size() == 0) {
      list << "No Categories. Create new...";
      qDebug() << "DB emtpy!";
    } else {
      while (query.next()) {
        list.append(query.value(0).toString());
      }
    }

  } else {
    qDebug() << query.lastError();
    qDebug() << query.lastQuery();
  }
  return list;
}

bool DBHandler::addMainItem(QString name,
                            QStringList fieldNames,
                            QStringList fieldTypes) {
  QString fields;
  db.open();

  // prepare query
  query.prepare("INSERT INTO " + TABLE_MAIN + " (" + COLUMN_MAIN_NAME +
                ") VALUES (:name);");
  // bind value
  query.bindValue(":name", name);

  // exec and check if successful
  // add to mainTable
  if (!query.exec()) {
    qDebug() << query.lastError();
    qDebug() << query.lastQuery();
    return false;
  }

  // create field string
  for (int i = 0; i < fieldNames.size(); i++) {
    fields += fieldNames.at(i) + " " + fieldTypes.at(i) + ",";
  }

  // exec and check if successful
  // add table
  if (!query.exec(" CREATE TABLE IF NOT EXISTS " + name +
                  " (id INTEGER PRIMARY KEY, " + fields +
                  " Price FLOAT, count INTEGER);")) {
    qDebug() << query.lastError();
    qDebug() << query.lastQuery();
    return false;
  }

  return true;
}

QMap<QString, QVariant::Type> DBHandler::getTableDetails(QString mainCat) {
  QMap<QString, QVariant::Type> fields;
  db.open();

  // exec and check if successful

  if (query.exec("SELECT * FROM " + mainCat + " WHERE 1"))
    for (int i = 0; i < db.driver()->record(mainCat).count(); i++) {
      qDebug() << i;
      fields[db.record(mainCat).field(i).name()] =
          db.record(mainCat).field(i).type();
    }

  // if failure
  else {
    qDebug() << query.lastError();
    qDebug() << query.lastQuery();
  }
  return fields;
}

QMap<QString, QString> DBHandler::getItem(QString cat, int id) {
  QMap<QString, QString> record;

  db.open();

  // exec and check if successful
  if (!query.exec("SELECT * FROM " + cat + " WHERE id = " +
                  QString::number(id))) {
    qDebug() << query.lastError();
    qDebug() << query.lastQuery();
  }  // if successful
  else {
    query.first();

    for (int i = 0; i < query.record().count(); i++)
      record.insert(query.record().field(i).name(), query.value(i).toString());
  }
  return record;
}

bool DBHandler::addItem(QString mainCat,
                        QStringList fields,
                        QStringList values) {
  // puts fields inside one string for query
  QString fieldsString;
  for (int i = 0; i < fields.size(); i++) {
    if (i != fields.size() - 1) {
      fieldsString += fields.at(i) + ", ";
    } else {
      fieldsString += fields.at(i);
    }
  }

  // puts values inside one string for query
  QString valuesString;
  for (int i = 0; i < fields.size(); i++) {
    if (i != values.size() - 1) {
      valuesString += ":" + fields.at(i) + ", ";
    } else {
      valuesString += ":" + fields.at(i);
    }
  }

  // prepare query for safety
  query.prepare("INSERT INTO " + mainCat + " (" + fieldsString + ") VALUES(" +
                valuesString + ")");

  // binds values
  for (int i = 0; i < values.size(); i++) {
    query.bindValue(":" + fields.at(i), values.at(i));
  }

  // exec and check if successful
  if (query.exec())
    return true;

  else {
    qDebug() << query.lastError();
    return false;
  }
}

void DBHandler::setMainField(QString mainCat, QString field) {
  // prepare query
  query.prepare(
      "UPDATE  main_table SET mainField=:field WHERE main_name=:mainCat");

  // bind values
  query.bindValue(":field", field);
  query.bindValue(":mainCat", mainCat);

  // exec and check if successful
  if (!query.exec()) {
    qDebug() << query.lastError();
    qDebug() << query.lastQuery();
  }
}

QString DBHandler::getMainField(QString MainCat) {
  QString mainField;

  db.open();

  // exec query
  query.exec("SELECT mainField FROM " + TABLE_MAIN + " WHERE " +
             COLUMN_MAIN_NAME + "=\"" + MainCat + "\"");
  query.last();

  // check that result count == 1
  if (query.at() + 1 == 1) {
    // moves to first, might be useless since only one result
    query.first();
    // gets data
    mainField = query.value(0).toString();
  } else {
    qDebug() << "Multiple mainCats! " << (query.at() + 1);
    qDebug() << query.lastQuery();
    mainField = "Error";
  }
  return mainField;
}

void DBHandler::open() {
  if (!db.open()) {
    qDebug() << "didn't open";
    qDebug() << db.lastError();
  }
}

void DBHandler::updateItem(QString mainCat,
                           int id,
                           QStringList fields,
                           QStringList values) {
  // open db
  db.open();

  // loop
  // updates one field and a time
  for (int i = 0; i < fields.size(); i++) {
    if (!query.exec("UPDATE " + mainCat + " SET " + fields.at(i) + " = " +
                    values.at(i) + " WHERE id =" + QString::number(id))) {
      qDebug() << query.lastError();
      qDebug() << query.lastQuery();
    }
  }

  // cloe db
}
