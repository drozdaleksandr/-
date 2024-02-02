#ifndef ZAKL_H
#define ZAKL_H
#include <string>

class zakl
{
private:
std::string name;
std::string surname;
std::string gender;
std::string date;
std::string diagnosis;
int age;
public:
zakl(std::string a_name, std::string a_surname, std::string a_gender, std::string a_date, std::string a_diagnosis, int age);
};

#endif // ZAKL_H
