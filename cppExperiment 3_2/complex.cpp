#include <iostream>
using namespace std;

class Complex{
    private:
        double real, imag;
    public:
        Complex(double r=0, double i=0){
            real = r;
            imag = i;
        }
        void display(){
            cout << real << " + " << imag << "i" << endl;
        }
        Complex operator+(Complex c){
            return Complex(real+c.real,imag+c.imag);
        }
        friend Complex operator+(double r,Complex c){
            return Complex(r+c.real,c.imag);
        }
};

int main(){
    Complex a(2,5), b(7,8), c(0,0);
    c = a + b;
    c.display();
    c = 4.1 + a;
    c.display();
    return 0;
}