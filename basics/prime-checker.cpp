#include <iostream>
using namespace std;

void checkPrime(int num);

int main(){
    int num;
    cout<<"Enter the number : ";
    cin>>num;
    checkPrime(num);
    return 0;
}

void checkPrime(int num){
bool isPrime=true;
 if(num<2){
  cout<<"invalid number"<<endl;
  return;
}
else if(num==2){
  cout<<num<<" is a prime number"<<endl;
  return;
}
for(int i=2;i<num;i++){
 if(num%i==0){
    isPrime=false;
    break;
  }
}
if(isPrime==false){
  cout<<num<<" is not a prime number."<<endl;
}
else if(isPrime==true){
  cout<<num<<" is a prime number."<<endl;
}
}