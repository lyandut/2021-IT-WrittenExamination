#include <iostream>
#include <string>
#include <stack>
using namespace std;

string func(string& str) {
    stack<char> stk;
    for(char ch : str) {
        if(ch==')') {
            string tmp;
            while(stk.top()!='(') {
                tmp += stk.top();
                stk.pop();
            }
            stk.pop();
            for(char c : tmp) stk.push(c);
        }
        else {
            stk.push(ch);
        }
    }
    string res;
    while(!stk.empty()) {
        res += stk.top();
        stk.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string str;
    cin >> str;
    cout << func(str) << endl;
    return 0;
}
