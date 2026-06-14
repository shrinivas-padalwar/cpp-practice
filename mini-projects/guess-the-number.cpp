#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void guessNumber();

int main(){
    guessNumber();
    return 0;
}

void guessNumber(){
  int st=-1;
  srand(time(0));

while(st!=0){
  cout<<"|| Guess the number ||"<<endl<<endl;
  cout<<"1.Start"<<endl<<"2.Exit"<<endl;
  cin>>st;
  if(st!=1){
    break;
  }else{
  
  int num=rand()%100+1;
  int ans=-1;
  int count=1;
  while(ans!=num){
  cout<<"Enter 0 to exit"<<endl;
  cout<<"Guess the number : ";
  cin>>ans;
  if(ans==0){
    cout<<"Better luck next time!"<<endl<<"No. of tries : "<<--count;
    break;
  }else if(ans<0||ans>100){
    cout<<"Invalid number!Try again."<<endl;
    continue;
  }
   else if(ans==num){
    cout<<"You guess correctly!"<<endl<<"No. of tries : "<<count<<endl;
    break;
  }
   else if(ans>num){
    cout<<"Wrong Answer!"<<endl<<"Number is smaller than that."<<endl<<"Current no. of attempts : "<<count<<endl;
    count++;
  }else if(ans<num){
    cout<<"Wrong Answer!"<<endl<<"Number is greater than that."<<endl<<"Current no. of attempts : "<<count<<endl;
    count++;
  }
  cout<<endl<<endl;
  } 
}
  cout<<endl; 
}
}