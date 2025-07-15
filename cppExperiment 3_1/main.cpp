#include <iostream>
#include <cmath>
using namespace std;

class Geometric_shape {
public:
    virtual void Show()=0;
    virtual double perimeter()=0;
    virtual double area()=0;
    virtual double volume()=0;
    virtual ~Geometric_shape(){};
};

class Rectangle:public Geometric_shape{
    protected:
        double width,height;
    public:
        Rectangle(double w,double h):width(w),height(h){};
        void Show(){
            cout<<"矩形"<<endl;
        }
        double perimeter(){
            return 2*(width+height);
        }
        double area(){
            return width*height;
        }
        double volume(){
            return 0;
        }
        ~Rectangle(){};
};
class Circle:public Geometric_shape{
    protected:
        double radius;
    public:
        Circle(double r):radius(r){};
        void Show(){
            cout<<"圆"<<endl;
        }
        double perimeter(){
            return 2*3.1415926*radius;
        }
        double area(){
            return 3.1415926*radius*radius;
        }
        double volume(){
            return 0;
        }
        ~Circle(){};
};
class Triangle:public Geometric_shape{
    private:
        double a,b,c;
    public:
        Triangle(double x,double y,double z):a(x),b(y),c(z){};
        void Show(){
            cout<<"三角形"<<endl;
        }
        double perimeter(){
            return a+b+c;
        }
        double area(){
            double p=perimeter()/2;
            return sqrt(p*(p-a)*(p-b)*(p-c));
        }
        double volume(){
            return 0;
        }
        ~Triangle(){};
};

class Box:public Rectangle{
    private:
        double depth;
    public:
        Box(double w,double h,double d):Rectangle(w,h),depth(d){};
        void Show(){
            cout<<"长方体"<<endl;
        }
        double volume(){
            return area()*depth;
        }
        ~Box(){};
};
class Cylinder:public Circle{
    private:
        double height;
    public:
        Cylinder(double r,double h):Circle(r),height(h){};
        void Show(){
            cout<<"圆柱"<<endl;
        }
        double volume(){
            return area()*height;
        }
        ~Cylinder(){};
};
class Cone:public Circle{
    private:
        double height;
    public:
        Cone(double r,double h):Circle(r),height(h){};
        void Show(){
            cout<<"圆锥"<<endl;
        }
        double volume(){
            return (area()*height)/3;
        }
        ~Cone(){};
};
class T_pyramid:public Triangle{
    private:
        double height;
    public:
        T_pyramid(double x,double y,double z,double h):Triangle(x,y,z),height(h){};
        void Show(){
            cout<<"三棱锥"<<endl;
        }
        double volume(){
            return (area()*height)/3;
        }
        ~T_pyramid(){};
};
class T_prism:public Triangle{
    private:
        double height;
    public:
        T_prism(double x,double y,double z,double h):Triangle(x,y,z),height(h){};
        void Show(){
            cout<<"三棱柱"<<endl;
        }
        double volume(){
            return area()*height;
        }
        ~T_prism(){};
};

int main() {
    Geometric_shape * gs[]={new Circle(10),new Rectangle(6,8), new
    Triangle(3,4,5), new Box(6,8,3), new Cylinder(10,3), new Cone(10,3), new 
    T_pyramid(3,4,5,3), new T_prism(3,4,5,3)};
    for (int i=0;i<8;i++){
        gs[i]->Show(); // 输出图形的类型，如“圆形”
        cout<<endl;
    }
    cout<<"平面图形："<<endl;
    for (int i=0;i<3;i++) {
        cout<<"图形周长："<<gs[i]->perimeter()<<'\t';
        cout<<"图形面积："<<gs[i]->area()<<'\t';
        cout<<"图形体积："<<gs[i]->volume()<<endl;
    }
    cout<<"立体图形："<<endl;
    for (int i=3;i<8;i++) {
        cout<<"图形底周长："<<gs[i]->perimeter()<<'\t';
        cout<<"图形底面积："<<gs[i]->area()<<'\t';
        cout<<"图形体积："<<gs[i]->volume()<<endl;
    }
    return 0;
}