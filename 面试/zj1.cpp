#include <iostream> 

using namespace std;

/*
题目：要求修改变量a的值，但不能直接使用a。
考察：栈向低地址扩展(即”向下生长”)，是连续的内存区域。
*/

int main() {
    int a=10;
    int b=0;
    cout << &a << endl;
    cout << &b << endl;
    int *p = &b;
    ++p;
    cout << p << endl;
    *p = 20;

    // cout << sizeof(b) << endl;

    cout << a <<endl;
    return 0;
}
