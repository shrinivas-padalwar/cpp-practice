#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(string str);

int main(){
    string input;
    cout<<"Enter input : ";
    getline(cin, input);

    if(isPalindrome(input)){
        cout<<"It is a palindrome"<<endl;
    } else {
        cout<<"It is not a palindrome"<<endl;
    }
    return 0;
}

bool isPalindrome(string str){
  int st=0;
  int e=str.length()-1;
  
  while(st<e){
    if(!isalnum(str[st])){
    st++;
    continue;
  }
  if(!isalnum(str[e])){
    e--;
    continue;
  }
   if(tolower(str[st])!=tolower(str[e])){
    return false;
   }
   st++;e--;

  }
  return true;
}