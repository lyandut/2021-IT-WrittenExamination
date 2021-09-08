#include <iostream>
#include <string>
#include <map>

using namespace std;

/*
指数合并
输入：x^2*y*y^2*z^3
输出：x2y3z3
*/

bool is_char(char ch) { return ch >= 'a' && ch <= 'z'; }

bool is_number(char ch) { return ch >= '1' && ch <= '9'; }

int get_number(string& str, int s, int t) {
    int res = 0;
    for(int i=s; i<=t; ++i) {
        res *= 10;
        res += (str[i]-'0');
    }
    return res;
}

string func(string& input) {
    map<char, int> mp;
    for(int i=0; i<input.size();) {
        if(input[i] == '*') {
            i++;
            continue;
        }
        if(is_char(input[i])) {
            if(input[i+1] == '^') {
                int s = i+2;
                int j = s;
                while(j<input.size() && is_number(input[j])) j++;
                mp[input[i]] += get_number(input, s, j-1);
                i = j;
            }
            else {
                mp[input[i]] = 1;
                i++;
            }
        }
    }
    string res;
    for(auto iter=mp.begin(); iter!=mp.end(); ++iter) {
        res += iter->first + to_string(iter->second);
    }
    return res;
}

int main() {
    string input = "x^2*y*y^2*z^3";
    cout << func(input) << endl;
    return 0;
}
