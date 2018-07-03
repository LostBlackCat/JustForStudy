#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  QWidget * window=new QWidget();
  window->resize(320,240);
  w.setGeometry(100,100,200,120);
  w.show();
  window->show();
  window->setWindowTitle("Doubel Window");
  w.show();
  return a.exec();
}
