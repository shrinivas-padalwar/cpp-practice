#include <iostream>
#include <vector>
using namespace std;

void atmSimulator();

int main(){
    atmSimulator();
    return 0;
}

void atmSimulator(){
  int balance=0;
  vector<int>accountHistory;
while(true){
  cout<<"1. Check Balance"<<endl<<"2. Deposit money"<<endl<<"3. Withdraw money"<<endl<<"4. Transaction history"<<endl<<"5. Exit"<<endl;
int opt=0;
cin>>opt;

//Check Balance
if(opt==1){
cout<<"Current Balance : "<<balance<<endl;
}
//Deposit money
else if(opt==2){
int deposit=0;
cout<<"Deposit amount : ";
cin>>deposit;
balance+=deposit;
accountHistory.push_back(deposit);
cout<<"1. Check current balance"<<endl;
cout<<"2. Exit"<<endl;
int choice=0;
cin>>choice;
if(choice==1){
  cout<<"Current balance : "<<balance<<endl;
}
}
//Withdraw money
else if(opt==3){
int withdraw=0;
cout<<"Withdrawal amount : ";
cin>>withdraw;
if(withdraw>balance){
  cout<<"Insufficient balance"<<endl;
}
else{
  balance-=withdraw;
accountHistory.push_back(-withdraw);
}

cout<<"1. Check current balance"<<endl;
cout<<"2. Exit"<<endl;
int choice=0;
cin>>choice;
if(choice==1){
  cout<<"Current balance : "<<balance<<endl;
}
}
//Show transaction history
else if(opt==4){
if(accountHistory.empty()){
    cout<<"No transactions yet."<<endl;
}
for(int val : accountHistory){
if(val<0){
  cout<<"Amount debited : "<<val<<endl;
}
else{
  cout<<"Amount credited : "<<val<<endl;
}
}
}
//Exit
else{
  break;
}}
}