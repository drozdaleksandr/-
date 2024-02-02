#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secondwindow.h"
#include "thirdwindow.h"



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
MainWindow(QWidget *parent = nullptr);
~MainWindow();
secondwindow c;
thirdwindow t;

private slots:
void on_pushButton_clicked();

void on_pushButton_2_clicked();

private:
Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
