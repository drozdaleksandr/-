#include "anotherwindow.h"
#include "ui_anotherwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

anotherwindow::anotherwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::anotherwindow)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
    ui->privet->setReadOnly(true);
    ui->vvodsurname->setReadOnly(true);
    ui->vvodmedcard->setReadOnly(true);
    ui->vvodeyes->setReadOnly(true);
    ui->vvoddiagnoz->setReadOnly(true);
    ui->vvodrec->setReadOnly(true);
}
anotherwindow::~anotherwindow()
{
    delete ui;
}
void anotherwindow::on_pognali_clicked()
{
    this->close();      // Закрываем окно
    emit firstWindow(); // И вызываем сигнал на открытие главного окна
}

void anotherwindow::on_lefteye_valueChanged(int arg1)
{
    ui->lefteye->setMinimum(-17);
    ui->lefteye->setMaximum(13);
}
void anotherwindow::on_righteye_valueChanged(int arg1)
{
    ui->righteye->setMinimum(-17);
    ui->righteye->setMaximum(13);
}
void anotherwindow::on_vvelidanye_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt)"));

        if (filename.isEmpty())
            return;

        QFile file("okoolist.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream out(&file);
        out << "surname: " << ui->surname->text() << endl;
        out << "Medical card number: " << ui->numbmedcard->text() << endl;
        out << "Diagnosis: " << ui->diagnoz->text() << endl;
        out << "Treatment recommendations: " << ui->recomendation->text() << endl;
        out << "Indicators of the left eye: " << ui->lefteye->value() << endl;
        out << "Indicators of the right eye: " << ui->righteye->value() << endl;

        file.close();
}



void anotherwindow::on_ochistit_clicked()
{
    ui->surname->clear();
    ui->lefteye->setValue(0);
    ui->righteye->setValue(0);
    ui->recomendation->clear();
    ui->diagnoz->clear();
    ui->numbmedcard->clear();
}

void anotherwindow::on_otkrit_clicked()
{
   QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть файл"), "", tr("Текстовые файлы (*.txt)"));
    if (!fileName.isEmpty())
    {
                QFile file(fileName);
                if (file.open(QIODevice::ReadOnly | QIODevice::Text))
                {
                    QTextStream in(&file);
                    QString surname = "";
                    QString numbmedcard = "";
                    QString diagnoz = "";
                    QString recomendation = "";
                    QString lefteye = "";
                    QString righteye = "";
                    while (!in.atEnd())
                    {
                        QString line = in.readLine();
                        QStringList parts = line.split(": ");
                        if (parts.length() == 2)
                        {
                            QString key = parts[0];
                            QString value = parts[1];
                            if (key == "surname")
                            {
                                surname = value;
                            }
                            else if (key == "Medical card number")
                            {
                                numbmedcard = value;
                            }
                            else if (key == "Diagnosis")
                            {
                                diagnoz = value;
                            }
                            else if (key == "Treatment recommendations")
                            {
                                recomendation = value;
                            }
                            else if (key == "Indicators of the left eye")
                            {
                                lefteye = value;
                            }
                            else if (key == "Indicators of the right eye")
                            {
                                righteye = value;
                            }
                         }
                    }
                    ui->surname->setText(surname);
                    ui->numbmedcard->setText(numbmedcard);
                    ui->lefteye->setValue(lefteye.toInt());
                    ui->righteye->setValue(righteye.toInt());
                    ui->diagnoz->setText(diagnoz);
                    ui->recomendation->setText(recomendation);

                   file.close();
               }
     }
}
