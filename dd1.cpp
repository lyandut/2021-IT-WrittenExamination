#include <iostream>
#include <string>
using namespace std;

int helper(string& str, int i, int j) {
    int res = 0;
    while(i>=0 && j<str.size() && 
        (str[i] == str[j] || str[i]=='*' || str[j]=='*')) {
        res += i==j ? 1 : 2;
        i--;
        j++;
    }
    return res;
}

int main() {
    string str;
    cin >> str;
    int res = 0;
    for(int i=0; i<str.size(); ++i) {
		int r1 = helper(str, i, i);
        int r2 = helper(str, i, i+1);
        res = max(res, r1);
        res = max(res, r2);
    }
    cout << res << endl;
    return 0;
}