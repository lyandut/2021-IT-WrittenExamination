/*
给定一个字符串s， 找出s中最长的回文子串
S = “babad”
输出：”bab”
实例：“abcdsdc”
*/

#include <iostream>
#include <string>
using namespace std;

int get_len(string& str, int l, int r, int& index) {
    while(l>=0 && r<str.size() && str[l]==str[r]) {
        l--;
        r++;
    }
    index = l+1;
    return r-l-1;
}

string func(string& str) {
    int max_len = 0, max_index = -1;
    for(int i=0; i<str.size(); ++i) {
        int a_index, b_index;
        int a = get_len(str, i, i, a_index);
        int b = get_len(str, i, i+1, b_index);
        if(a > max_len) {
            max_len = a;
            max_index = a_index;
        }
        if(b > max_len) {
            max_len = b;
            max_index = b_index;
        }
    }
    return str.substr(max_index, max_len);
}

int main() {
    string str = "abcdsdc";
    cout << func(str) << endl;
    return 0;
}