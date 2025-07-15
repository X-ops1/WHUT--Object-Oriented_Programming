#include <iostream>
#include "MyClass.h"
#include "MyClass.cpp"
using namespace std;

int main(){
    MyClass obj1,obj2(5,8);
    obj1.Set(1,3);
    obj1.Print();
    obj2.Print();
    return 0;
}