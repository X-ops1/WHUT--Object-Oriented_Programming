#include <iostream>
using namespace std;

class Rectangle{
    private:
        float length;
        float width;
    public:
        Rectangle(float l=0, float w=0){
            length = l;
            width = w;
        }
        float area(){
            return length * width;
        }
        float perimeter(){
            return 2 * (length + width);
        }
};

int main(){
    Rectangle a(20,50),b(3.6,4.5);
    cout << "Area of Rectangle A is: " << a.area() << endl;
    cout << "Perimeter of Rectangle A is: " << a.perimeter() << endl;
    cout << "Area of Rectangle B is: " << b.area() << endl;
    cout << "Perimeter of Rectangle B is: " << b.perimeter() << endl;
    return 0;
}