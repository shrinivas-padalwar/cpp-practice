#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void contact();
void sortContact(vector<pair<string,long long>>&contact);
void searchAllContact(vector<pair<string,long long>>&contact);
void deleteContact(vector<pair<string,long long>>&contact,int idx);
void searchContact(vector<pair<string,long long>>&contact,string &target);
int findContact(vector<pair<string,long long>>&contact,string &target);
bool isValidNum(long long num);
void addContact(vector<pair<string,long long>>&contact);

int main(){
    contact();
    return 0;
}

void contact(){
vector<pair<string,long long>>contact;
string target;
cout<<"1. Contacts"<<endl;
cout<<"2. Exit"<<endl;
int choice=0;
cin>>choice;
if(choice==1){
int choose=0;
while(choose!=4){
  sortContact(contact);
cout<<"1. All contacts"<<endl;
cout<<"2. Search contact"<<endl;
cout<<"3. Add contact"<<endl;
cout<<"4. Exit"<<endl;
  cin>>choose;
   cin.ignore();
  if(choose==1){
   if(contact.empty()){
    cout<<"Your contact list is empty"<<endl;
   }
   else{
    searchAllContact(contact);
    cout<<endl;
   }
  }
  else if(choose==2){
    cout<<"Enter name : ";
    string target;
    getline(cin,target);
    searchContact(contact,target);
  }
  else if(choose==3){
    addContact(contact);
  }
}
}
}
void sortContact(vector<pair<string,long long>>&contact){
  if(contact.size()<2) return;
  for(int i=0;i<contact.size()-1;i++){
    bool isSorting=false;
    int idx=i;
    for(int j=0;j<contact.size();j++){
      if(contact[idx].first>contact[j].first){
        idx=j;
        isSorting=true;
      }
    }
    swap(contact[idx],contact[i]);
    if(!isSorting){
      break;
    }
  }
}
void searchAllContact(vector<pair<string,long long>>&contact){
  for(const auto&val:contact){
    cout<<val.first<<endl;
  }
}
void deleteContact(vector<pair<string,long long>>&contact,int idx){
  cout<<"Are you sure you want to delete this contact?"<<endl;
  cout<<"1. Sure"<<endl;
  cout<<"2. Cancel"<<endl;
  int opt=0;
  cin>>opt;
  if(opt==1){
      contact.erase(contact.begin()+idx);
      cout<<"Contact deleted succesfully"<<endl;
      return;
  }
  else{
    return;
  }
}
void searchContact(vector<pair<string,long long>>&contact,string &target){
  int idx=findContact(contact,target);
  if(idx==-1){
    cout<<"No contact exist"<<endl;
    return;
  }
  else{
    cout<<contact[idx].first<<endl;
    cout<<"1. View contact"<<endl;
    cout<<"2. Delete contact"<<endl;
    cout<<"3. Exit"<<endl;
    int opt=0;
    cin>>opt;
    if(opt==1){
      cout<<"Name : "<<contact[idx].first<<endl;
      cout<<"Number : "<<contact[idx].second<<endl;
      cout<<"1. Edit"<<endl;
      cout<<"2. Exit"<<endl;
      int choice=0;
      cin>>choice;
      if(choice==1){
        int choose=0;
        while(choose!=3){
        cout<<"1. Name"<<endl;
        cout<<"2. Number"<<endl;
        cout<<"3. Exit"<<endl;          
          cin>>choose;
          cin.ignore();
          if(choose==1){
            string name;
            cout<<"Name : ";
            getline(cin,name);
            contact[idx].first=name;
          }
          if(choose==2){
            long long num=0;
            cout<<"Number : ";
            cin>>num;
            if(isValidNum(num)!=true)while(!isValidNum(num)){
              cout<<"Invalid number"<<endl;
              cout<<"1. Enter number"<<endl;
              cout<<"2. Exit"<<endl;
              int j=0;
              if(j==2){
                break;
              }
              else if(j==1){
                cout<<"Number : ";
                cin>>num;
              }
            }
            contact[idx].second=num;
          }
        }
      }
      else return;
    }
   else if(opt==2){
    deleteContact(contact,idx);
   }
   else return;
  }
  return;
}
int findContact(vector<pair<string,long long>>&contact,string &target){
  for(int i=0;i<contact.size();i++){
    if(target==contact[i].first){
      return i;
    }
  }
  return -1;
}
bool isValidNum(long long num){
  int count=0;
  while(num>0){
    num/=10;
    count++;
  }
  if(count!=10){
    return false;
  }
  else return true;
}
void addContact(vector<pair<string,long long>>&contact){
int choice=0;
cout<<"1. Create new contact"<<endl;
cout<<"2. Exit"<<endl;
cin>>choice;
if(choice==2){
  return ;
}
else if(choice==1){
string tempName;
long long num;
cout<<"Name : ";
cin.ignore();
getline(cin,tempName);
cout<<"Number : ";
cin>>num;
if(!isValidNum(num)){while(!isValidNum(num)){
cout<<"Invalid Number"<<endl;
cout<<"1. Edit number"<<endl;
cout<<"2. Exit"<<endl;
int opt=0;
cin>>opt;
if(opt==1){
  cout<<"Num : ";
  cin>>num;
}
else{
  break;
}
}
}
else if(isValidNum(num)){
  int opt=0;
  cout<<"1. Save"<<endl;
  cout<<"2. Exit"<<endl;
  cin>>opt;
  if(opt==1){
    contact.push_back({tempName,num});
  }
  else{
    return;
  }
}
}
}