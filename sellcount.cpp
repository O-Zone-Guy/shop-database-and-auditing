#include "sellcount.h"
#include "ui_sellcount.h"
#include "dbhandler.h"
#include "sell.h"

SellCount::SellCount(Sell* sellWindow, DBHandler* handler, QWidget* parent)
    : QDialog(parent),
      ui(new Ui::sellCount),
      handler(handler),
      sellWindow(sellWindow) {
  ui->setupUi(this);
  connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accepted()));
  connect(this, SIGNAL(addedItem()), sellWindow, SLOT(updateItems()));
}

SellCount::~SellCount() {
  delete ui;
}

void SellCount::getItem(QString mainCat, int id) {
  QMap<QString, QString> item = handler->getItem(mainCat, id);

  ui->mainField->setText(item.value(handler->getMainField(mainCat)));
  ui->price->setText(item.value("Price"));
  ui->mainCat->setText(mainCat);
  ui->id->setText(QString::number(id));

  ui->spinBox->setMaximum(item.value("count").toInt());

  open();
}

void SellCount::accepted() {
  QDir mDir;
  QFileInfo fileInfo(mDir.currentPath() + "/files");
  // creates dir
  if (!fileInfo.exists()) {
    if (mDir.mkdir(mDir.currentPath() + "/files")) {
    } else {
      qDebug() << "Didn't create dir";
      return;
    }
  }

  // opens and writes to file
  fileReader.setFileName(mDir.currentPath() + "/files/selling.txt");
  QTextStream stream(&fileReader);
  if (!fileReader.open(QFile::WriteOnly | QFile::Text | QFile::Append)) {
    qDebug() << "Could not open file";
    qDebug() << fileReader.error();
    return;
  } else {
    stream << ui->mainCat->text() + "," + ui->id->text() + "," +
                  ui->spinBox->text() + " "
           << endl;
    stream.flush();
    fileReader.close();
    if (!sellWindow->isVisible()) {
      sellWindow->open();
    }
    emit addedItem();
  }
}
