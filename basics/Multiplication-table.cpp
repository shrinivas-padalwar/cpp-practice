#include <iostream>
using namespace std;

void multiplicationTable(int n);

int main(){
  int num;
  cout<<"Enter Number : ";
  cin>>num;
  multiplicationTable(num);
  return 0;
}

void multiplicationTable(int n){

  for(int i=1;i<=10;i++){
    cout<<n<<" * "<<i<<" = "<<n*i<<endl;
  }
}