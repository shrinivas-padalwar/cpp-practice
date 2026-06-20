#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Account{
protected:
int accNum=0;
string userName=" ";
double balance=0;
public:
Account(string userName,int accNum,double balance){
    this->userName=userName;
    this->accNum=accNum;
    this->balance=balance;
}
void deposit(double amount){
    if(amount<=0){
        cout<<"Invalid amount"<<endl;
        return;
    }
    else{
        balance+=amount;
    }
}
 virtual void withdraw(double amount){
    if(amount<=0){
        cout<<"Invalid amount"<<endl;
        return;
    }
    else if(amount>balance){
        cout<<"Insufficient balance"<<endl;
        return;
    }else{
        balance-=amount;
        cout<<"Amount succesfully withdrew"<<endl;
    }
}
double getBalance(){
    return balance;
}
int getAccNum(){
    return accNum;
}
string getUserName(){
    return userName;
}
void displayInfo(){
    cout<<"Name : "<<getUserName()<<endl;
    cout<<"Account No. : "<<getAccNum()<<endl;
    cout<<"Balance : "<<getBalance()<<endl;
}
};
class SavingAccount : public Account{
private:
double interestRate=0;
public:
SavingAccount(string userName,int accNum,double balance) : Account(userName,accNum,balance){
}
void setInterest(double interestRate){
    this->interestRate=interestRate;
}
void applyInterest(){
    balance+=interestRate*balance/100;
}
void withdraw(double amount)override{
    if(balance<=1000||balance-amount<1000){
        cout<<"Insufficient balance"<<endl;
        return;
    }
    else{
        balance-=amount;
    }
}
};

class CurrentAccount : public Account{
private:
double overdraftLimit=0;
public:
CurrentAccount(string userName,int accNum,double balance) : Account(userName,accNum,balance){
}
void setOverdraftLimit(double limit){
    if(limit<0){
        cout<<"Invalid amount"<<endl;
        return;
    }
    else{
        overdraftLimit=limit;
        return;
    }
}
void withdraw(double amount)override{
    if(amount<=0){
        cout<<"Invalid amount"<<endl;
        return;
    }
    else if(amount>balance&&amount>balance+overdraftLimit){
        cout<<"Exceeds current balance and overdraft limit"<<endl;
        return;
    }
    else if(amount<=balance){
        balance-=amount;
    }
    else{
        overdraftLimit=balance+overdraftLimit-amount;
        balance-=amount;
        cout<<"Amount withdrew succesfuly"<<endl;
        cout<<"Overdraft limit remaining : "<<overdraftLimit<<endl;
        return;
    }
}
};


int main(){
    Account* accounts[2];
    accounts[0] = new SavingAccount("Test1", 1, 5000);
    accounts[1] = new CurrentAccount("Test2", 2, 1000);

    ((CurrentAccount*)accounts[1])->setOverdraftLimit(500);  // cast needed since base Account has no such method

    for(int i=0; i<2; i++){
        accounts[i]->withdraw(2000);
        accounts[i]->displayInfo();
    }
return 0;
}