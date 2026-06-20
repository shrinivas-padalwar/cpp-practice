#include <iostream>
using namespace std;

void TicTacToe();
void viewArr(char arr[][3]);
bool verifyWin(char arr[][3]);

int main(){
    TicTacToe();
    return 0;
}

void TicTacToe(){
cout<<"|Tic Tac Toe |"<<endl;
cout<<"1.Start"<<endl<<"2.Exit"<<endl;
int choice=0;
cout<<"Enter choice : ";
cin>>choice;
if(choice!=1){
  return ;
}
else{
  char arr[3][3];
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      arr[i][j]='.';
    } 
  }
  //interface
  
  bool isp1=true;
  int col,row;
   viewArr(arr);
   bool didWin=false;
   //Game playing
  for(int i=0;i<9;i++){

  if(isp1){
    cout<<"Player X turn"<<endl;
    cout<<"Column : ";
    cin>>col;
    cout<<"Row : ";
    cin>>row;
    if(arr[row-1][col-1]!='.'){
      cout<<"Cell already taken! Try again"<<endl;
      i--;
      continue;
    }
    arr[row-1][col-1]='X';
    isp1=false;
    viewArr(arr);
    if(verifyWin(arr)==true){
      cout<<"Player X wins! Congratulations to Player X for winning game"<<endl;
      didWin=true;
      break;
    }
  }
  else{
    cout<<"Player O turn"<<endl;
    cout<<"Column : ";
    cin>>col;
    cout<<"Row : ";
    cin>>row;
    if(arr[row-1][col-1]!='.'){
      cout<<"Cell already taken! Try again"<<endl;
      i--;
      continue;
    }
    arr[row-1][col-1]='O';
    isp1=true;
    viewArr(arr);
    if(verifyWin(arr)==true){
      cout<<"Player O wins! Congratulations to Player O for winning game"<<endl;
      didWin=true;
      break;
    }
  }
  }
  if(didWin==false){
    cout<<"Player X ties with Player O"<<endl;
  }
}
}
bool verifyWin(char arr[][3]){
  if((arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2] && (arr[0][0]=='X'||arr[0][0]=='O')) || (arr[2][0]==arr[1][1] && arr[1][1]==arr[0][2] && (arr[1][1]=='X'||arr[1][1]=='O'))){
    return true;
  }
  for(int i=0;i<3;i++){
    if((arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2]&&(arr[i][1]=='X'||arr[i][1]=='O')) || arr[0][i]==arr[1][i] && arr[1][i]==arr[2][i]&&(arr[1][i]=='X'||arr[1][i]=='O')){
      return true;
    }
  }
  return false;
}
void viewArr(char arr[][3]){
cout<<"   1  2  3"<<endl;
  for(int i=0;i<3;i++){
    cout<<i+1<<" ";
    
    for(int j=0;j<3;j++){
      cout<<"| ";
      cout<<arr[i][j];
    } 
    cout<<"|";
    cout<<endl;
    cout<<"  ___________"<<endl;;
  }
}