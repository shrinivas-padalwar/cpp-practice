#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class Rectangle{

public:
double length=0;
double width=0;
Rectangle(double length,double width){
    if(length<=0||width<=0){
        cout<<"Invalid number"<<endl;
    }else{
        this->length=length;
        this->width=width;
    }
}
double getPerimeter(){
    return 2*(length+width);
}
double getArea(){
    return length*width;
}
};

class Circle{
public:
double radius=0;
Circle (double radius){
    if(radius<=0){
        cout<<"Invalid number"<<endl;
    }else{
        this->radius=radius;
    }
}
double getPerimeter(){
    return 2*3.14*radius;
}
double getArea(){
    return 3.14*radius*radius;
}
};




int main(){
Rectangle r(5,8.7);
cout<<"Area : "<<r.getArea()<<endl;
cout<<"Perimeter : "<<r.getPerimeter()<<endl;
Circle c(5);
cout<<"Area : "<<c.getArea()<<endl;
cout<<"Perimeter : "<<c.getPerimeter()<<endl;

   return 0;
}