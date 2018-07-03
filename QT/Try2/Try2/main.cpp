#include "mainwindow.h"
#include <QApplication>
#include<QPushButton>
#include<QHBoxLayout>
#include<QLineEdit>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  QWidget * window=new QWidget();
  QPushButton *button=new QPushButton("Press me ",window);
  QHBoxLayout layout(window);
  QLineEdit *lineEdit=new QLineEdit("Line edit",window);

  window->resize(320,240);
  w.setGeometry(100,100,200,120);
  layout.addWidget(button);
  layout.addWidget(lineEdit);
  w.show();
  button->move(100,100);
  window->setWindowTitle("Doubel Window");
  button->show();
  window->show();
  w.close();
  return a.exec();
}
