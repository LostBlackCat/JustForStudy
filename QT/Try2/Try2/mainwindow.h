#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void on_pushButton_clicked();

  void on_pushButton_pressed();

  void on_pushButton_released();

  void on_button_clicked();

private:
  Ui::MainWindow *ui;
};
class Widget:public QWidget
{
  Q_OBJECT

public:
  explicit Widget(QWidget *parent=0);
  ~Widget();
private slots:
  void on_button_clicked();

  void click();
private:
};
#endif // MAINWINDOW_H
