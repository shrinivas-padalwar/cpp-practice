#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;




class Shapes{
protected:
double side2=0;
double side1=0;
public:
Shapes(){}
Shapes(double side1){
    this->side1=side1;
}
Shapes(double side1,double side2){
    this->side1=side1;
    this->side2=side2;
}
void setSide(double side1){
    this->side1=side1;
}
void setSide(double side1,double side2){
    this->side1=side1;
    this->side2=side2;
}
virtual double area()=0;
};

class Triangle:public Shapes{
public:
Triangle(){}
Triangle(double side1,double side2):Shapes(side1,side2){}
double area()override{
    return 0.5*side1*side2;
}
};

class Rectangle:public Shapes{
public:
Rectangle(){}
Rectangle(double side1,double side2):Shapes(side1,side2){}
double area()override{
    return side1*side2;
}
};

class Square:public Shapes{
public:
Square(){}
Square(double side1):Shapes(side1){}
double area()override{
    return side1*side1;
}
};
class Circle:public Shapes{
public:
Circle(){}
Circle(double side1):Shapes(side1){}
double area()override{
    return 3.14*side1*side1;
}
};




int main(){
vector<Shapes*>shapes;
shapes.push_back(new Circle(5));
shapes.push_back(new Rectangle(4,6));
shapes.push_back(new Triangle(3,8));
shapes.push_back(new Square(8));
for(Shapes*s:shapes){
    cout<<s->area()<<endl;
}

    return 0;
}