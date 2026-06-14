#include <iostream>
#include <string>
using namespace std;

void quizzGame();

int main(){
    quizzGame();
    return 0;
}

void quizzGame(){
string question[]={
  "What is 6*10?",
  "What is highest number between 1 to 1000?",
  "What is 60/3?",
  "What is 50*2?",
  "What is square of 29?"
};
int choice=-1;
int ans;
int score=0;
int answers[]={60,999,20,100,841};
while(true){
cout<<"|| Quizz Game ||"<<endl<<endl;
cout<<"1.Start"<<endl<<"2.End"<<endl;
cin>>choice;
if(choice!=1){
  break;
}

  else{for(int i=0;i<5;i++){  
    
    cout<<i<<")"<<question[i]<<" : ";
    cin>>ans;
    if(ans==answers[i]){
      cout<<"You answered correctly!"<<endl<<"Current score : "<<++score<<endl;
      
    }
    else{
      cout<<"Your answer is wrong!"<<endl<<"Current score : "<<score<<endl;
    }
  }
  cout<<"Your answered "<<5-score<<" questions wrong."<<endl<<"Your total score is "<<score<<endl;
  }
}
}