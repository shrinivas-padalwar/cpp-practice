#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;




class Book{
public:
string title;
string author;
int ISBN;
bool isIssued=false;
Book(string title,string author,int ISBN){
    this->title=title;
    this->author=author;
    this->ISBN=ISBN;
}
void Issued(){
    isIssued=true;
}
void Returned(){
    isIssued=false;
}
void showInfo(){
    cout<<"Title : "<<title<<" | Author : "<<author<<" | ISBN : "<<ISBN<<endl;
}
};
class Member{
public:
string name;
int memberID;
vector<Book*>borrowed;
Member(string name,int memberID){
    this->name=name;
    this->memberID=memberID;
}
void addBook(Book *b){
    borrowed.push_back(b);
}
void returnBook(int idx){
    if(idx>=0 && idx<borrowed.size()){
        borrowed[idx]->Returned();
    borrowed.erase(borrowed.begin()+idx);
    cout<<"Book succesfully returned"<<endl;
    }
    else{
        cout<<"Invalid book index"<<endl;
        return;
    }
}
};
class Library{
public:
vector<Book*>owned;
vector<Member*>joined;
void addNewBook(string title,string author,int ISBN){
    owned.push_back(new Book(title,author,ISBN));
}
void addNewMember(string name,int memberID){
    joined.push_back(new Member(name,memberID));
}
void issueBook(Book*b,Member*m){
    if(!b->isIssued){
    m->addBook(b);
    b->Issued();
      cout << "Success: " << b->title << " issued to " << m->name << endl;
    }else{
        cout << "Error: " << b->title << " is already checked out!" << endl;
    }

}
void returnBook(int idx,Member*m){
    m->returnBook(idx);

}
void searchBook(string name){
    for(auto &b:owned){
        if(b->title==name){
            b->showInfo();
            return;
        }
    }
    cout<<"Book is not in library"<<endl;
}
void displayAllBook(){
    for(auto&b : owned){
        b->showInfo();
        cout<<endl;
    }
}
void displayAllIssued(){
    bool anyIssued=false;
    for(auto&m : joined){
        if(m->borrowed.empty()){
            continue;
        }
        anyIssued=true;
            cout<<"Name : "<<m->name<<endl;
            for(auto& b : m->borrowed){
                cout<<"Name : "<<b->title<<" | ";
            }
            cout<<endl;
    }
    if(!anyIssued){
        cout<<"No books are currently issued."<<endl;
    }
}
    ~Library() {
        for (Book* b : owned) delete b;
        for (Member* m : joined) delete m;
    }
};


int main() {
    Library lib;

    // 1. Populate Library System
    lib.addNewBook("The C++ Programming Language", "Bjarne Stroustrup", 101);
    lib.addNewBook("Design Patterns", "Gang of Four", 202);
    lib.addNewMember("Alice Jones", 5001);

    cout << "--- Initial Book Inventory ---" << endl;
    lib.displayAllBook();

    // 2. Issue a book (Index 0 book to Index 0 member)
    cout << "\n--- Issuing Book Process ---" << endl;
    lib.issueBook(lib.owned[0], lib.joined[0]);

    // 3. Track Status updates
    cout << "\n--- Checking Active Loans ---" << endl;
    lib.displayAllIssued();

    // 4. Return the book via member's borrowed list tracker (Index 0 of their list)
    cout << "\n--- Returning Book Process ---" << endl;
    lib.returnBook(0, lib.joined[0]);

    // 5. Final validation check
    cout << "\n--- Final Inventory Check ---" << endl;
    lib.displayAllBook();

    return 0;
}