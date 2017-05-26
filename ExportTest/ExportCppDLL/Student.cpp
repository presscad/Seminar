#define _EXPORTING
#include "Student.h"

Student::Student(void) : m_Id(0), m_Name(""), m_Gender("��"), m_Age(0)
{
}

Student::Student(int Id, string Name, string Gender, int Age) : m_Id(Id), m_Name(Name), m_Gender(Gender), m_Age(Age)
{
}

Student::~Student(void)
{
}

void Student::printInfo() {
    cout << "ѧ�ţ�" << m_Id
        << " ������" << m_Name
        << " �Ա�" << m_Gender
        << " ���䣺" << m_Age
        << endl;
}

#undef _EXPORTING