#include <iostream>
using namespace std;
class Person{
	string name;
	int age;
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
	
};
const Person* getEmployee(){
	Person* p=new Person("jim",28);
	return p;
}
int main(void)
{
	Person p("paul",26);
	const Person* anEmployee=getEmployee();
	cout<<anEmployee->getName()<<endl;
	
	cout<<p.getName()<<endl<<p.getAge()<<endl;
	//const Person * getEmployee();
	delete anEmployee;
	return 0;
}
