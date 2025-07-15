#include <iostream>
#include <cmath>
using namespace std;

class MyPoint {
public:
    MyPoint(double x0, double y0) :x(x0), y(y0) {}
    MyPoint(MyPoint& np) :x(np.x), y(np.y) {}
    double getX() { return x; }
    double getY() { return y; }
    void setX(double x0) { x = x0; }
    void setY(double y0) { y = y0; }
    void setPoint(double x0, double y0) { x = x0; y = y0; }
    void setPoint(MyPoint& np) { x = np.x; y = np.y; }
    double getLength(MyPoint p) {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
    void printIt() { cout << " (" << x << "," << y << ") "; }
    private:
        double x, y;
};

class Triangle{
    MyPoint p1, p2, p3;
public:
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3) :p1(x1, y1), p2(x2, y2), p3(x3, y3){}
    Triangle(MyPoint& np1, MyPoint& np2, MyPoint& np3) : p1(np1), p2(np2), p3(np3) {}
    double getPerimeter() {
        return p1.getLength(p2) + p2.getLength(p3) + p3.getLength(p1);
    }
    double getArea(){
        double a = p1.getLength(p2);
        double b = p2.getLength(p3);
        double c = p3.getLength(p1);
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));   
    }

};

int main() {
    MyPoint x(2.2,2);
    MyPoint y(3.2,4);
    MyPoint z(5,6.5);
    Triangle a(x,y,z);
    Triangle b(0,0,0,3,4,0);
    cout << "Perimeter of triangle a is: " << a.getPerimeter() << endl;
    cout << "Area of triangle a is: " << a.getArea() << endl;
    cout << "Perimeter of triangle b is: " << b.getPerimeter() << endl;
    cout << "Area of triangle b is: " << b.getArea() << endl;
    return 0;
}