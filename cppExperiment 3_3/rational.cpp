#include <iostream>
using namespace std;

class Rational{
    private:
        int nr,dm;
    public:
        Rational(int n=0,int d=1){
            int a=n,b=d;
            while(a&&b){
                if(a>b)
                    a%=b;
                else
                    b%=a;
            }
            int t=a>b?a:b;
            nr=n/t;
            dm=d/t;
        };
        Rational operator+(const Rational& r){
            return Rational(nr*r.dm+dm*r.nr,dm*r.dm);
        }
        friend ostream& operator<<(ostream& out,const Rational &r){
            out<<r.nr<<"/"<<r.dm;
            return out;
        }

};

int main() {
    Rational x(1, 3), y(1, 6), z;
    z = x + y;
    cout << x << " + " << y << " = " << z << endl;
    return 0;
}