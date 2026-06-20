#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student{
string name;
int marks;
public:
Student(){
}
Student(string name,int marks){
       this->name=name;
       this->marks=marks;
} 
void showinfo(){
       cout<<"Name : "<<name<<endl;
       cout<<"Marks : "<<marks<<endl;

}
void setName(string name){
       this->name=name;
}
void setMarks(int marks){
       if(marks<0||marks>100){
              cout<<"Invalid marks"<<endl;
       }
       else{
              this->marks=marks;
       }
}
int getMarks(){
       return marks;
}
string getName(){
       return name;
}      

};

int main(){
       Student s1("Shrinivas Padalwar",90);
s1.setMarks(150);                          // should get rejected
cout << "Marks : " << s1.getMarks() << endl;  // should still show 90, not 150
       return 0;
}