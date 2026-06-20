#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Employee{
protected:
string name={};
string job={};
double salary=0;
public:
Employee(){
}
Employee(string name){
    this->name=name;
}
void setName(string name){
    this->name=name;
}
void setSalary(double salary){
    this->salary=salary;
}
string getName(){
    return name;
}
string getJob(){
    return job;
}
double getSalary(){
    return salary;
}
void showInfo(){
    cout<<"Name : "<<name<<endl;
    cout<<"Job : "<<job<<endl;
    cout<<"Salary : "<<salary<<endl;
}
};

class Developer : public Employee{
public:
Developer(){
    salary=60000;
    job="Developer";
}
Developer(string name):Employee(name){
  salary=60000;
  job="Developer";
}

};
class Manager : public Employee{
public:
Manager(){
    salary=100000;
    job="Manager";    
}
Manager(string name):Employee(name){
    salary=100000;
    job="Manager"; 
}

};



int main(){
Manager m("Shrinivas Padalwar");
m.showInfo();
Developer d("Raj Chandel");
d.showInfo();





    
    return 0;
}