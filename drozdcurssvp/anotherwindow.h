#ifndef ANOTHERWINDOW_H
#define ANOTHERWINDOW_H

#include <QWidget>
#include <QString>
#include<QLineEdit>
#include<QSpinBox>

namespace Ui {
class anotherwindow;
}

class anotherwindow : public QWidget
{
    Q_OBJECT
    class LineEdit : public QLineEdit
    {

    };

public:
    explicit anotherwindow(QWidget *parent = 0);
    ~anotherwindow();
signals:
    void firstWindow();  // Сигнал для первого окна на открытие
private slots:
    // Слот-обработчик нажатия кнопки
    void on_pognali_clicked();
    void on_lefteye_valueChanged(int arg1);

    void on_righteye_valueChanged(int arg1);

    void on_vvelidanye_clicked();

    void on_ochistit_clicked();

    void on_otkrit_clicked();

private:
    Ui::anotherwindow *ui;
    QSpinBox *righteye;
    QSpinBox *lefteye;
    QLineEdit *lineEdit;
};

#endif // ANOTHERWINDOW_H
