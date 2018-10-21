#include "sell.h"
#include "ui_sell.h"
#include "dbhandler.h"
#include <QLabel>

Sell::Sell(DBHandler* handler, QWidget* parent)
    : QDialog(parent), ui(new Ui::sell), handler(handler) {
  ui->setupUi(this);
}

Sell::~Sell() {
  delete ui;
}

void Sell::sell(QString mainCat, int id) {
  show();
}

void Sell::updateItems() {
  // clear lists
  mainCats.clear();
  mainFields.clear();
  counts.clear();
  prices.clear();
  totals.clear();

  // set up file edit objects
  fileInfo = new QFileInfo(QDir::currentPath() + "/files");
  file = new QFile(QDir::currentPath() + "/files/selling.txt");
  stream = new QTextStream(file);

  // file exist check
  if (!fileInfo->exists()) {
    qDebug() << "Dir doesn't exist";
  } else {
    // open file
    if (file->open(QFile::ReadOnly)) {
      QStringList lines;

      // read from file
      while (!stream->atEnd()) {
        // write to list
        lines.append(stream->readLine());
      }

      // add row to gridLayout
      for (int i = 0; i < lines.size(); i++) {
        // get id
        QString mainCat = lines.at(i).split(",").at(1);
        int id = mainCat.toInt();

        // get count
        mainCat = lines.at(i).split(",").at(2);
        int count = mainCat.toInt();

        // get mainCat
        mainCat = lines.at(i).split(",").at(0);

        // get item
        QMap<QString, QString> item = handler->getItem(mainCat, id);

        // append to lists
        mainCats.append(new QLabel(mainCat, this));
        mainFields.append(
            new QLabel(item.value(handler->getMainField(mainCat))));
        prices.append(new QLabel(item.value("Price"), this));
        counts.append(new QLabel(QString::number(count), this));

        // get price and append
        double total = count * item.value("Price").toDouble();
        totals.append(new QLabel(QString::number(total), this));

        // insert row
        ui->gridLayout->addWidget(mainCats.at(i), (i + 1), 0);
        ui->gridLayout->addWidget(mainFields.at(i), (i + 1), 2);
        ui->gridLayout->addWidget(prices.at(i), (i + 1), 4);
        ui->gridLayout->addWidget(counts.at(i), (i + 1), 6);
        ui->gridLayout->addWidget(totals.at(i), (i + 1), 8);
      }

      // get final total
      double total = 0;
      for (QLabel* label : totals) {
        total += label->text().toDouble();
      }

      // insert total bottom
      ui->total->setText(QString::number(total));
      QFont font = ui->total->font();
      font.setPointSize(10);
      font.setUnderline(true);
      font.setBold(true);
      ui->total->setFont(font);

    } else {
      qDebug() << "Couldn't open file!";
      qDebug() << file->error();
    }
  }
}

void Sell::on_buttonBox_accepted() {
  file = new QFile(QDir::currentPath() + "/files/selling.txt");
  stream = new QTextStream(file);
  QString line;
  QString mainCat;
  int id;
  int count;
  if (file->open(QFile::ReadOnly)) {
    while (!stream->atEnd()) {
      line = stream->readLine();
      mainCat = line.split(",").at(1);
      id = mainCat.toInt();

      mainCat = line.split(",").at(2);
      count = mainCat.toInt();

      mainCat = line.split(",").at(0);

      handler->sellItem(mainCat, id, count);
    }

    file->remove();
    emit sold();

  } else {
    qDebug() << "couldn't open file";
    qDebug() << file->error();
  }
  file->close();
}

// handle being rejected💔
void Sell::reject() {
  file->remove();
  hide();
}
