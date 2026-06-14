#include <iostream>
using namespace std;

void printFizzBuzz();

int main(){
    printFizzBuzz();
    return 0;
}

void printFizzBuzz(){
  for(int i=1;i<=100;i++){
  if(i%3==0 && i%5==0){
    cout<<"FizzBuzz ";
  }
  else if(i%3==0){
    cout<<"Fizz ";
  }
  else if(i%5==0){
    cout<<"Buzz ";
  }
  else{
    cout<<i<<" ";
  }
}
}