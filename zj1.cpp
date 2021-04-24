#include <iostream> 

using namespace std;

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
