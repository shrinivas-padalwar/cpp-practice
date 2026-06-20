#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;





class Complex{
public:
    double real,imag;
    Complex(double r,double i){
        real=r;
        imag=i;
    }
    Complex operator+(Complex other){
        Complex result(real+other.real,(imag+other.imag));
        return result;
    }
    void display(){
        if(imag<0){
            cout<<real<<" - "<<(-imag)<<"i"<<endl;
        }
        else{
            cout<<real<<" + "<<imag<<"i"<<endl;
        }
    }
};
ostream& operator<<(ostream& out,Complex c){
    if(c.imag<0){
            out<<c.real<<" - "<<(-c.imag)<<"i"<<endl;
        }
        else{
            out<<c.real<<" + "<<c.imag<<"i"<<endl;
        }
        return out;
    }


int main(){
Complex c4(3, -5);
c4.display();        // should show: 3 - 5i
cout << c4 << endl;   // should show: 3 - 5i

    return 0;
}