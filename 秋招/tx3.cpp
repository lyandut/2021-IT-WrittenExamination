#include <iostream>
#include <string>
using namespace std;

int func(string& str) {
    int c0 = 0, c1 = 0;
    for(char ch : str) {
        if(ch=='0') c0++;
        else c1++;
    }
    int a, b, c;
    if(c0!=c1) {
        a = c0 > c1 ? c0 : c1;
        c = c0 > c1 ? '0' : '1';
    }
    else {
        // 这里有bug，来不及改了！！！
        a = str.front() == '1' ? c0 : c1;
        c = str.front() == '1' ? '0' : '1';
    }
    int b1=0, b2=0;
    for(int i=0; i<str.size(); ++i) {
        if(str[i]==c) break;
        b1++;
    }
    for(int i=str.size()-1; i>=0; --i) {
        if(str[i]==c) break;
        b2++;
    }
    b = max(b1, b2);
    return a*(a+1)/2 + b*(b+1)/2;
}

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    cout << func(str) << endl;
    return 0;
}