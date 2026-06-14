#include <iostream>
using namespace std;

void reversenum();

int main(){
    reversenum();
    return 0;
}

void reversenum(){
  int num;
 cout<<"Enter number : "<<endl;
 cin>>num;
 int originalNum=num;
 int revNum=0;
 while(num>0){
  revNum=revNum*10+num%10;
  num/=10; 
 }
  cout<<"Reverse No. of "<<originalNum<<" is "<<revNum<<endl;
}