#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student{
private:
string name={};
int marks[6];
int rollNo=0;
public:
Student(string name,int rollNo){
    this->name=name;
    this->rollNo=rollNo;
}
void setName(string name){
    this->name=name;
}
void setRollNo(int rollNo){
    this->rollNo=rollNo;
}
void setMarks(int marks,int idx){
    if(marks<0||marks>100){
        cout<<"invalid marks"<<endl;
    }else{
       this->marks[idx]=marks;
    }
}
void getMarks(){
    for(int i=0;i<6;i++){
        cout<<marks[i]<<" ";
    }
    cout<<endl;
}
string getName(){
    return name;
}
int getRollNo(){
    return rollNo;
}
int getTotalMarks(){
    int totalMarks=marks[0]+marks[1]+marks[2]+marks[3]+marks[4]+marks[5];
    return totalMarks;
}
double getAverage(){
    return (double)getTotalMarks()/6;
}
char getGrade(){
    if(getAverage()>=90){
        return 'A';
    }
    else if(getAverage()>=75){
        return 'B';
    }
    else if(getAverage()>=60){
        return 'C';
    }    
    else if(getAverage()>=40){
        return 'D';
    }    
    else {
        return 'F';
    }    
}
void displayInfo(){
    cout<<"Name : "<<getName()<<endl;
    cout<<"Roll no : "<<getRollNo()<<endl;
    cout<<"Marks : ";
    getMarks();
    cout<<"Total Marks : "<<getTotalMarks()<<endl;
    cout<<"Average : "<<getAverage()<<endl;
    cout<<"Grade : "<<getGrade()<<endl;
}
};


int main(){
    Student s1("Shrinivas Padalwar",01);
    s1.setMarks(90,0);
    s1.setMarks(95,1);
    s1.setMarks(96,2);
    s1.setMarks(89,3);
    s1.setMarks(99,4);
    s1.setMarks(96,5); 
    s1.displayInfo();  

return 0;
}