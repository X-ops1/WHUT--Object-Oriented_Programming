#include<iostream> 
using namespace std; 
class IntArray {
public:
    IntArray(int sz); // 数组初始化为 sz 个元素，初值全为 0
    IntArray( int *array, int sz ) ; // 用静态数组 array 的前 sz 个元素初始化新数组
    IntArray( const IntArray &rhs ) ; // 复制构造函数
    void printAll();
    ~IntArray(); // 析构函数
private:
    int *ia;
    int size;
    void initializeArray(int sz,int value=0);
};
void IntArray::initializeArray(int sz,int value)
{
    size = sz; 
    ia = new int[ size ]; 
    for ( int ix=0; ix < size; ++ix ) 
    ia[ix ] = value;
}
IntArray::IntArray( int sz ) { 
    initializeArray(sz);
}
IntArray:: IntArray( int *array, int sz ) { 
    initializeArray(sz);
    for (int ix = 0; ix < size; ++ix) {
        ia[ix] = array[ix]; // 拷贝数据
    }
}
IntArray:: IntArray( const IntArray &rhs ) 
{ 
    initializeArray(rhs.size);
    for (int ix = 0; ix < size; ix++) {
        ia[ix] = rhs.ia[ix]; // 拷贝数据
    }
}
void IntArray::printAll()
{
    for ( int ix=0; ix < size; ++ix ) 
    cout<<ia[ix]<<" "; 
    cout<<endl;
}
IntArray::~IntArray() { delete[] ia; } // 析构函数
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    IntArray arr1(10), arr2(a,5),arr3(arr2);
    arr1.printAll();
    arr2.printAll();
    arr3.printAll();
    return 0;
}