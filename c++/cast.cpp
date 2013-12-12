#include <iostream>
using namespace std;
class Person{
	string name;
	int  age;
public:
	Person(){ cout<<this<<" "<<name<<" Person()"<<endl;}
	Person(string name, int age):name(name),age(age){cout<<name<<" Person()"<<endl; }
	Person(const Person& other){
		name=other.name;
		age=other.age;
	}
	Person& operator=(const Person& other){
		if(this==&other){
			return *this;
		}
		this->name=other.name;
		this->age=other.age;
	}
	~Person(){cout<<name<<" ~Person()"<<endl;}
	const string& getName()const{return name;}
	const int& getAge()const{return age;}
	void setName(const string& name)
	{
		this->name=name;
	}
	
};
const Person* getEmployee(){
	Person* p=new Person("jim",28);
	return p;
}
int main(void)
{
	const int  ic = 100;
	const int *pc = &ic;
	const_cast<int &>(ic)++;
	cout<<ic<<","<<*pc<<endl;

	cout<<"============================="<<""<<endl;
	const volatile int c = 10;
    int *j = const_cast<int*>(&c);
	const_cast<int&>(c)=2;
    cout<<c<<" "<<*j<<endl;
    cout<<&c<<" "<<j<<endl;//有意思的现象
	cout<<"============================="<<""<<endl;
	const Person p("paul",26);
	Person p2 = const_cast<Person&>(p);
	p2.setName("paul3");
	//const_cast<Person&>(p).setName("paul2");
	cout<<p.getName()<<endl<<p.getAge()<<endl;
	cout<<"============================="<<""<<endl;
	
	const Person* anEmployee=getEmployee();
	
	cout<<anEmployee->getName()<<endl;
	
	const_cast<Person*>(anEmployee)->setName("jim2");
	cout<<anEmployee->getName()<<endl;
	
	//const Person * getEmployee();
	delete anEmployee;
	return 0;
}
