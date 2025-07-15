#include <iostream>
using namespace std;

const int MaxSize = 100; // 栈中能保存的最多元素个数
template <typename T>
class IStack {
public:
    IStack(); // 栈的构造函数
    void Push(T &n); // 往栈顶增加元素
    void Pop(); // 从非空栈的栈顶删除一个元素
    T GetTop(); // 返回非空栈的栈顶元素
    bool Empty(); // 判断栈是否为空
    int Size(); // 返回栈中元素的个数
    void ClearStack(); // 将栈清空
    ~IStack(); // 栈的析构函数
private:
    T elem[MaxSize]; // 保存栈中各元素的数组
    int Top; // 保存栈顶的当前位置
};
template <typename T>
IStack<T>::IStack(){
    Top = -1; // 栈为空时，栈顶位置为-1
}
template <typename T>
void IStack<T>::Push(T &n){
    if(Top == MaxSize-1){ // 栈满时，不能再增加元素
        cout << "栈满，不能再增加元素！" << endl;
        return;
    }
    elem[++Top] = n; // 栈顶位置后移，并将元素存入栈顶
}
template <typename T>
void IStack<T>::Pop(){
    if(Top == -1){ // 栈空时，不能再删除元素
        cout << "栈空，不能再删除元素！" << endl;
        return;
    }
    elem[Top--]; // 栈顶元素出栈
}
template <typename T>
T IStack<T>::GetTop(){
    if(Top == -1){ // 栈空时，不能获取栈顶元素
        cout << "栈空，不能获取栈顶元素！" << endl;
        return -1;
    }
    return elem[Top];
}
template <typename T>
bool IStack<T>::Empty(){
    return Top == -1;
}
template <typename T>
int IStack<T>::Size(){
    return Top+1;
}
template <typename T>
void IStack<T>::ClearStack(){
    Top = -1;
}
template <typename T>
IStack<T>::~IStack(){
}

int main(){
    IStack<int> intStack;
    IStack<char> charStack;

    // 整数栈操作
    for (int i = 0; i < 5; ++i)
        intStack.Push(i);

    cout << "Int stack size: " << intStack.Size() << endl;
    while (!intStack.Empty()) {
        cout << "Popped from int stack: " << intStack.GetTop() << endl;
        intStack.Pop();
    }
    cout << "Int stack is empty" << endl;

    // 字符栈操作
    char chars[] = "hello";
    for (int i=0;chars[i]!='\0';i++)
        charStack.Push(chars[i]);

    cout << "Char stack size: " << charStack.Size() << endl;
    while (!charStack.Empty()) {
        cout << "Popped from char stack: " << charStack.GetTop() << endl;
        charStack.Pop();
    }
    cout << "Char stack is empty" << endl;

    return 0;
}