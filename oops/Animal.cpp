#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Animal{
protected:
string eat="Omnivore";
string sleep="Night";
public:
// Animal(){
// this->eat="Omnivore";
// this->sleep="Night";
// }
string getEat(){
    return eat;
}
string getSleep(){
    return sleep;
}
};


class Dog : public Animal{
private :
string sound="Bark";
public:
string getSound(){
    return sound;
}
};


class Cat : public Animal{
private :
string sound="Meow own";
public:
string getSound(){
    return sound;
}
};




int main(){
Dog d;
cout<<"Eat : "<<d.getEat()<<endl;
cout<<"Sleep : "<<d.getSleep()<<endl;
cout<<"Sound : "<<d.getSound()<<endl;
Cat c;
cout<<"Eat : "<<c.getEat()<<endl;
cout<<"Sleep : "<<c.getSleep()<<endl;
cout<<"Sound : "<<c.getSound()<<endl;



    return 0;
}