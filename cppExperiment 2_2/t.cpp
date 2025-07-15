#include <iostream>
using namespace std;

class Point {
public:
    Point(double xv,double yv) {x = xv;y = yv;}
    Point(Point& pt) { x = pt.x; y = pt.y; }
    double getx() { return x; }
    double gety() { return y; }
    double Area() { return 0; }
    void Show() { cout<<"x="<<x<<' '<<"y="<<y<<endl; }
private:
    double x,y;
};
class Rectangle : public Point {
public:
    Rectangle(double xv,double yv,double w,double h):Point(xv,yv) { width = w; height = h; }
    Rectangle(Point& p,double w,double h):Point(p) { width = w; height = h; }
    int position(Point &pt)
    {
        if((pt.getx()>getx()&&pt.getx()<getx()+width&&pt.gety()<gety()&&pt.gety()>gety()-height))
            return 1;
        else if((pt.getx()<getx()||pt.getx()>getx()+width||pt.gety()>gety()||pt.gety()<gety()-height))
            return -1.;
        else
            return 0;
    }
    double getwidth() { return width; }
    double getheight() { return height; }
    double Area() { return width*height; }
    void Show() { cout<<"x="<<getx()<<' '<<"y="<<gety()<<' '<<"width="<<width<<' '<<"height="<<height<<endl; }
private:
    double width,height;
};
class Circle : public Point {
public:
    Circle(double xv,double yv,double r):Point(xv,yv) { radius = r; }
    Circle(Point& p,double r):Point(p) { radius = r; }
    int position(Point &pt)
    {
        double dis = (pt.getx()-getx())*(pt.getx()-getx())+(pt.gety()-gety())*(pt.gety()-gety());
        if(dis<radius*radius)
            return 1;
        else if(dis>radius*radius)
            return -1;
        else
            return 0;
    }
    double getradius() { return radius; }
    double Area() { return 3.1415926*radius*radius; }
    void Show() { cout<<"x="<<getx()<<' '<<"y="<<gety()<<' '<<"radius="<<radius<<endl; }
private:
    double radius;
};
void check(int n){
    if(n==1)
        cout << "inside" << endl;
    else if(n==-1)
        cout << "outside" << endl;
    else
        cout << "on the boundary" << endl;
}
int main() {
    // 测试 Point 类
    cout << "Testing Point class:" << endl;
    Point p1(3.5, 4.5);
    p1.Show();
    cout << "Area of point: " << p1.Area() << endl;

    // 测试 Rectangle 类
    cout << "\nTesting Rectangle class:" << endl;
    Rectangle rect1(1.0, 2.0, 5.0, 6.0); // 使用坐标和宽高初始化
    rect1.Show();
    cout << "Area of rectangle: " << rect1.Area() << endl;

    // 使用 Point 对象初始化 Rectangle
    Point pt(7.0, 8.0);
    Rectangle rect2(pt, 3.0, 4.0);
    rect2.Show();
    cout << "Area of rectangle: " << rect2.Area() << endl;

    // 测试 position 方法
    Point testPt1(2.5, -3.5);
    cout << "Test Point (" << testPt1.getx() << ", " << testPt1.gety() << ") is ";
    check(rect1.position(testPt1));

    Point testPt2(9.0, 10.0);
    cout << "Test Point (" << testPt2.getx() << ", " << testPt2.gety() << ") is ";
    check(rect1.position(testPt2));

    // 测试边界情况
    Point testPt3(1.0, 2.0); // 左上角顶点
    cout << "Test Point (" << testPt3.getx() << ", " << testPt3.gety() << ") is ";
    check(rect1.position(testPt3));

    Point testPt4(6.0,-4.0); // 右下角顶点
    cout << "Test Point (" << testPt4.getx() << ", " << testPt4.gety() << ") is ";
    check(rect1.position(testPt4));

    // 测试 Circle 类
    cout << "\nTesting Circle class:" << endl;
    Circle circ1(5.0, 5.0, 3.0); // 使用坐标和半径初始化
    circ1.Show();
    cout << "Area of circle: " << circ1.Area() << endl;

    // 使用 Point 对象初始化 Circle
    Circle circ2(pt, 2.0);
    circ2.Show();
    cout << "Area of circle: " << circ2.Area() << endl;

    // 测试 position 方法
    Point testPt5(5.5, 5.5);
    cout << "Test Point (" << testPt5.getx() << ", " << testPt5.gety() << ") is ";
    check(circ1.position(testPt5));

    Point testPt6(10.0, 10.0);
    cout << "Test Point (" << testPt6.getx() << ", " << testPt6.gety() << ") is ";
    check(circ1.position(testPt6));

    // 测试边界情况
    Point testPt7(5.0, 8.0); // 圆周上的点
    cout << "Test Point (" << testPt7.getx() << ", " << testPt7.gety() << ") is ";
    check(circ1.position(testPt7));

    return 0;
}