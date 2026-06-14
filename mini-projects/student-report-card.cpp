#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

void studentReportCard();
void inputSubjectMarks(vector<vector<pair<string,int>>>&marks,vector<string>&name,vector<pair<string,int>>&pass,pair<string,int>&topper,vector<pair<string,int>>&fail,int &deadline,vector<int>&average,vector<int>&totalMarks);
void outputSubjectMarks(vector<vector<pair<string,int>>>&marks,vector<string>&name,int &deadline,vector<int>&average,vector<int>&total);
void passList(vector<pair<string,int>>&pass,int &deadline);
void failList(vector<pair<string,int>>&fail,int &deadline);
void viewTopper(pair<string,int>&topper);

int main(){
    studentReportCard();
    return 0;
}

void studentReportCard(){
vector<vector<pair<string,int>>>marks;
vector<pair<string,int>>pass;
vector<pair<string,int>>fail;
vector<string>name;
pair<string,int>topper={"None",INT_MIN};
vector<int>average;
vector<int>total;
int deadline;
bool isInput=false;
while(true){
cout<<"1. Input student's report card"<<endl;
cout<<"2. Show student's report card"<<endl;
cout<<"3. Exit"<<endl;
int choose;
cin>>choose;

if(choose==3){
  break;
}
else if(choose==1){
 inputSubjectMarks(marks,name,pass,topper,fail,deadline,average,total);
 isInput=true;
}
else if(choose==2){
  if(isInput==true){
  int opt=0;
  while(true){
cout<<"1. Show all student report card"<<endl;
cout<<"2. Show topper"<<endl;
cout<<"3. Show pass student's list"<<endl;
cout<<"4. Show fail student's list"<<endl;
cout<<"5. Exit"<<endl;
cin>>opt;
if(opt==1){
  outputSubjectMarks(marks,name,deadline,average,total);
}
else if(opt==2){
  viewTopper(topper);
}
else if(opt==3){
  passList(pass,deadline);
}
else if(opt==4){
  failList(fail,deadline);
}
else{
  break;
}

  }

  }
else{
  cout<<"You didn't input student report card yet"<<endl;
}
}
}

}
void viewTopper(pair<string,int>&topper){
  cout<<"Student name : "<<topper.first<<endl<<"Total Marks : "<<topper.second<<endl;
}
void failList(vector<pair<string,int>>&fail,int &deadline){
  cout<<"Deadline marks : "<<deadline<<endl;
if(fail.empty()){
    cout<<"Everyone passed"<<endl;
    return;
}else
for(int i=0;i<fail.size();i++){
  cout<<"Student name : "<<fail[i].first<<"\t\tMarks : "<<fail[i].second<<endl;
}
}
void passList(vector<pair<string,int>>&pass,int &deadline){
  cout<<"Deadline marks : "<<deadline<<endl;
  if(pass.empty()){
    cout<<"No one passed!"<<endl;
    return;
  }else
for(int i=0;i<pass.size();i++){
  cout<<"Student name : "<<pass[i].first<<"\t\tMarks : "<<pass[i].second<<endl;
}
}
void outputSubjectMarks(vector<vector<pair<string,int>>>&marks,vector<string>&name,int &deadline,vector<int>&average,vector<int>&total){
 
    cout<<"Deadline marks : "<<deadline<<endl;
  for(int i=0;i<name.size();i++){
  
    
    cout<<"Student name : "<<name[i]<<endl;
    for(int j=0;j<6;j++){
      cout<<"Subject : "<<marks[i][j].first<<endl;
      cout<<"Marks : "<<marks[i][j].second<<endl;
    }
    cout<<"Average marks : "<<average[i]<<endl;
    cout<<"Total Marks : "<<total[i]<<endl;
    if(total[i]>=deadline){
      cout<<"Result : Pass"<<endl;
    }
    else{
      cout<<"Result : Fail"<<endl;
    }
    cout<<endl;
  }
}
void inputSubjectMarks(vector<vector<pair<string,int>>>&marks,vector<string>&name,vector<pair<string,int>>&pass,pair<string,int>&topper,vector<pair<string,int>>&fail,int &deadline,vector<int>&average,vector<int>&totalMarks){
  cout<<"Set deadline marks : ";
  cin>>deadline;
  while(true){
    cout<<"1. Enter"<<endl<<"2. Exit"<<endl;
    int choice=0;
    cin>>choice;
    if(choice==2){
      break;
    }
    else{
      while(true){
        int total=0;
        cout<<"Student name : ";
        cin.ignore();
        string tempName;
        getline(cin,tempName);
        name.push_back(tempName);

        vector<pair<string,int>>studentSubject;
        for(int j=0;j<6;j++){
          int mark=0;
          string subject;

          if(j==0) subject="English";
          else if(j==1) subject="Marathi";
          else if(j==2) subject="Sanskrit";
          else if(j==3) subject="Math";
          else if(j==4) subject="Science";
          else if(j==5) subject="Social Science";

          cout<<subject<<" Marks : ";
          cin>>mark;

          if(mark>100||mark<0){
            cout<<"Invalid number! Try again!"<<endl;
            j--;
            continue;
          }

          studentSubject.push_back({subject,mark});
          total+=mark;
        }

        marks.push_back(studentSubject);
        totalMarks.push_back(total);
        average.push_back(total/6);

        if(total>topper.second){
          topper={tempName,total};
        }

        if(total>=deadline){
          pass.push_back({tempName,total});
        }
        else{
          fail.push_back({tempName,total});
        }

        cout<<"1. Next"<<endl<<"2. Exit"<<endl;
        int opt;
        cin>>opt;
        if(opt!=1){
          break;
        }
      }
    }
  }
}