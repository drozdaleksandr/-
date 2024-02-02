#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QWidget>
#include <QString>
#include "zakl.h"

namespace Ui {
class secondwindow;
}

class secondwindow : public QWidget
{
Q_OBJECT

public:
explicit secondwindow(QWidget *parent = nullptr);
~secondwindow();
int i=1;

private slots:
void on_add_button_clicked();

private:
Ui::secondwindow *ui;
};

#endif // SECONDWINDOW_H
