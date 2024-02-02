#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include <fstream>
#include <QDebug>
thirdwindow::thirdwindow(QWidget *parent)
: QWidget(parent)
, ui(new Ui::thirdwindow)
{
ui->setupUi(this);
}

thirdwindow::~thirdwindow()
{
delete ui;
}


void thirdwindow::on_del_button_clicked()
{
std::vector<std::string> vec;
std::ifstream file("zapisi.txt");
if (file.is_open())
{
std::string str;
while (std::getline(file, str))
vec.push_back(str);
file.close();
for (int i=0; i<vec.size(); i++)
{
if(ui->spinBox->value()>vec.size())
{
QMessageBox::critical(this, "Message", "ERROR");
break;
}
if(vec[i]==std::to_string(ui->spinBox->value())+"/")
{
l=i;
qInfo()<<i;
}
}
for (int k=0; k<vec.size(); k++)
{
if(vec[k]==std::to_string(ui->spinBox->value()+1)+"/")
{
j=k;
qInfo()<<k;
}
}
vec.erase(vec.begin()+l, vec.begin()+j);
std::ofstream fout;
fout.open("zapisi.txt");
for (int i=0; i<vec.size(); i++)
{
fout<< vec[i]<< std::endl;
}
l=0;
j=0;
}
this->close();
}
