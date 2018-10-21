#include "mainwindow.h"
#include "sell.h"
#include "dbhandler.h"
#include "additem.h"
#include "ui_mainwindow.h"
#include "sellcount.h"
#include <QDebug>
#include <Qt>
#include <QMessageBox>
#include <QDir>
#include <QFileInfo>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      handler(new DBHandler(this)),
      sellWindow(new Sell(handler)),
      addItemWindow(new AddItem(handler, this)),
      sellcount(new SellCount(sellWindow, handler, this)) {
  ui->setupUi(this);

  // setting up combobox
  spinnerModel.setStringList(handler->getAllMainCat());
  ui->comboBox->setModel(&spinnerModel);

  // setting up QTableView
  handler->open();
  queryModel.setQuery("SELECT * FROM " + ui->comboBox->currentText() +
                      " WHERE 1");
  handler->close();
  ui->dataOutput->setModel(&queryModel);
  ui->dataOutput->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Stretch);
  ui->dataOutput->setSelectionMode(QAbstractItemView::SingleSelection);
  ui->dataOutput->setSelectionBehavior(QAbstractItemView::SelectRows);

  // connecting signals and slots
  connect(addItemWindow, SIGNAL(newCatAdded()), this, SLOT(updateComboModel()));
  connect(sellWindow, SIGNAL(sold()), this, SLOT(updateQuery()));
  connect(addItemWindow, SIGNAL(addedItem()), this, SLOT(updateQuery()));

  // checking for sellting.txt file and handling it
  QFileInfo fileInfo(QDir::currentPath() + "/files/selling.txt");
  if (fileInfo.exists()) {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::information(
        this, "Selling File",
        "Selling file already exists, do you wish to delete it?",
        QMessageBox::No, QMessageBox::Yes);
    if (reply == QMessageBox::Yes) {
      qDebug() << "Hello!";
      QFile file(fileInfo.dir().currentPath() + "/files/selling.txt");
      file.remove();
    } else {
      sellWindow->open();
      sellWindow->updateItems();
    }
  }
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_sellButton_clicked() {
  // check for selection and handling
  if (ui->dataOutput->selectionModel()->selection().count() != 0) {
    int id =
        ui->dataOutput->model()
            ->index(ui->dataOutput->selectionModel()->currentIndex().row(), 0)
            .data()
            .toInt();
    sellcount->getItem(ui->comboBox->currentText(), id);
  }
}

void MainWindow::on_dataOutput_doubleClicked(const QModelIndex& index) {
  // get id

  int id;
  QString mainCat;
  if (index.isValid()) {
    id = queryModel.index(index.row(), 0).data().toInt();
    mainCat = ui->comboBox->currentText();
  } else {
    qDebug() << "issues";
    return;
  }
  sellcount->getItem(mainCat, id);
}

void MainWindow::on_serachBox_textEdited(const QString& arg1) {
  // well done you bastard!
  queryModel.setQuery("SELECT * FROM " + ui->comboBox->currentText() +
                          " WHERE " +
                          handler->getMainField(ui->comboBox->currentText()) +
                          " LIKE \'%" + arg1 + "%\'",
                      handler->getDB());

  ui->dataOutput->setModel(&queryModel);
}

void MainWindow::on_addItems_clicked() {
  // add item
  if (ui->dataOutput->selectionModel()->selectedRows().count() == 0)
    addItemWindow->open(ui->comboBox->currentText());

  // edit item
  else
    addItemWindow->openEdit(
        ui->comboBox->currentText(),
        ui->dataOutput->model()
            ->index(ui->dataOutput->selectionModel()->currentIndex().row(), 0)
            .data()
            .toInt());
  ui->dataOutput->selectionModel()->selectedRows().clear();
  ui->dataOutput->selectionModel()->clear();
}

void MainWindow::updateComboModel() {
  spinnerModel.setStringList(handler->getAllMainCat());
}

void MainWindow::on_comboBox_currentTextChanged(const QString& arg1) {
  queryModel.setQuery("SELECT * FROM " + arg1 + " WHERE 1");
}

void MainWindow::updateQuery() {
  queryModel.setQuery("SELECT * FROM " + ui->comboBox->currentText() +
                      " WHERE 1");
  ui->dataOutput->setModel(&queryModel);
}
