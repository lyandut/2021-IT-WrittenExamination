#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> func2(vector<int>& a, unordered_map<int, int>& mp) {
    vector<int> res;
    for(int aa : a) {
        if(mp.count(aa)) res.push_back(mp[aa]);
        else {
            int cnt = 0;
            for(int i=1; i<=aa/2; ++i) {
                if(aa % i == 0) cnt++;
            }
            res.push_back(cnt);
            mp[aa] = cnt;
        }
    }
    return res;
}

int func(vector<int>& a, vector<int>& b) {
    unordered_map<int, int> mp;
    vector<int> aa = func2(a, mp);
    vector<int> bb = func2(b, mp);
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    int cnt = 0;
    int i=0, j=0;
    while(i<aa.size()) {
        if(aa[i]>bb[j]) {
            cnt++;
            i++;
            j++;
        }
        else {
            i++;
        }
    }
    return cnt;
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i) cin >> b[i];
    cout << func(a, b) << endl;
    return 0;
}