#include "secondwindow.h"
#include <fstream>
#include "ui_secondwindow.h"
using namespace std;


secondwindow::secondwindow(QWidget *parent)
: QWidget(parent)
, ui(new Ui::secondwindow)
{
ui->setupUi(this);
}

secondwindow::~secondwindow()
{
delete ui;
}

void secondwindow::on_add_button_clicked()
{
QString a_name=ui->name_line->text();
QString a_surname=ui->surname_line->text();
QString a_gender=ui->gender_line->currentText();
QString a_diagnosis=ui->diagnosis_line->toPlainText();
QString a_date=ui->dateEdit->text();
std::ofstream fout;
fout.open("zapisi.txt", std::ofstream::app);

std::ifstream fin("zapisi.txt");

string str;
getline(fin, str);
if (str!="")
{
    fin.seekg(-1,ios_base::end);
    bool keepLooping = true;
    while(keepLooping) {
        char ch;
        fin.get(ch);
        if((int)fin.tellg() <= 1) {
            fin.seekg(0);
            keepLooping = false;
        }
        else if(ch == '\n') {
            keepLooping = false;
        }
        else {
            fin.seekg(-2,ios_base::cur);
        }
    }
    string lastLine;
    getline(fin,lastLine);
    i=stoi(lastLine);
    i++;
    fin.close();
    fout« std::endl;
}
fout << i<< "/"<<std::endl;
fout<< "name:"<< a_name.toStdString()<< std::endl;
fout<< "surname:"<< a_surname.toStdString()<< std::endl;
fout<< "gender:"<< a_gender.toStdString()<< std::endl;
fout<< "date:"<< a_date.toStdString()<< std::endl;
fout<< "diagnosis:"<< a_diagnosis.toStdString()<< std::endl;
fout<< "age:"<< ui->age_spinbox->value()<< std::endl;
fout<< i;
fout.close();
i++;
this->close();
}
