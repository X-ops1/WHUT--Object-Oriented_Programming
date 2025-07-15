#ifndef MYCLASS_H
#define MYCLASS_H

#include<iostream> 

class MyClass{
    public:
        MyClass(int a = 0, int b = 0); 
        void Print(); 
        void Set(int a, int b); 
    private: 
        int x, y; 
};

#endif