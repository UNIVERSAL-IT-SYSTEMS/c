//***********************
//**    ch12_11.cpp    **
//***********************

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class StudentID{
public:
  StudentID(int id=0)
  {
    value=id;
    cout <<"Assigning student id " <<value <<endl;  }
  ~StudentID()
  {
    cout <<"Destructing id " <<value <<endl;
  }
protected:
  int value;
};

class Student{
public:
  Student(const char* pName="noName",int ssID=0)
  {
    cout <<"Constructing student " <<pName <<endl;    strncpy(name,pName,sizeof(name));
    name[sizeof(name)-1]='\0';
	cout<<name<<endl;
    StudentID id(ssID);     //ϣ����ѧ�Ŵ���ѧ�������
  }
protected:
  char name[20];
  StudentID id;
};

int  main()
{
  Student s("Randysssssssssssssssssssssssssssssssssssssss",9818);
			// Randysssssssssssssss
			   //Randyssssssssssssss
  return 0;
}
