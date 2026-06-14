#include <iostream>
#include <string>
using namespace std;

void vowelCounter();

int main(){
    vowelCounter();
    return 0;
}

void vowelCounter(){
  string input;
  char vowel[5]={'a','e','i','o','u'};
  cout<<"Enter input : ";
  getline(cin,input);
  int count=0;
  for(int i=0;i<size(input);i++){
    for(int j=0;j<5;j++){
      if((vowel[j])==tolower(input[i])){
        count++;
        break;
      }
    }
  }
  cout<<"Number of Vowels : "<<count<<endl;
}