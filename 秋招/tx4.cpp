#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

string dp(int n, unordered_map<int, string>& mp) {
    if(n==2) return "101";
    if(n==3) return "111";
    if(mp.count(n)) return mp[n];
    string str = n%2 ? "1" : "0";
    mp[n] = dp(n/2, mp) + str + dp(n/2, mp);
    return mp[n];
}

int func(int n, int l, int r) {
    unordered_map<int, string> mp;
    string str = dp(n, mp);
    int res = 0;
    for(int i=l-1; i<=r-1; ++i) {
        if(str[i]=='1') res++;
    }
    return res;
}

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    cout << func(n, l, r) << endl;
    return 0;
}