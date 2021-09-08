#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

int bfs(string& str) {
    string correct = str;
    sort(correct.begin(), correct.end());
    if(str == correct) return 0;
    
    int res = 0;
    queue<string> q;
    q.push(str);
    unordered_set<string> st;
    st.insert(str);
    while(!q.empty()) {
        int sz = q.size();
        for(int i=0; i<sz; ++i) {
            auto curr = q.front(); q.pop();
            for(int len=2; len<=str.size(); ++len) {
                string tmp = curr;
                reverse(tmp.begin(), tmp.begin()+len);
                if(st.count(tmp)) continue;
                if(tmp == correct) return res+1;
                q.push(tmp);
                st.insert(tmp);
            }
        }
        ++res;
    }
    return res;
}

int main() {
    int n, q;
    cin >> n >> q;
    while(q--) {
        string str;
        cin >> str;
        cout << bfs(str) << endl;
    }
    return 0;
}