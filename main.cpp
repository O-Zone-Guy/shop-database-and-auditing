#include <QApplication>
#include "dbhandler.h"
#include "mainwindow.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  a.setQuitOnLastWindowClosed(true);
  return a.exec();
}
