#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QWidget>
#include <QMessageBox>


namespace Ui {
class thirdwindow;
}

class thirdwindow : public QWidget
{
Q_OBJECT

public:
explicit thirdwindow(QWidget *parent = nullptr);
~thirdwindow();

private slots:
void on_del_button_clicked();

private:
int l,j=0;
Ui::thirdwindow *ui;
};

#endif // SECONDWINDOW_H
