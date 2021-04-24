#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool is_valid(vector<int>& track) {
    if(track.size()!=3) return false;
    int a=track[0], b=track[1], c=track[2];
    return a+b>c && a+c>b && b+c>a;
}

void dfs(vector<vector<int>>& res, vector<int>& track, vector<int>& arr, int s) {
    if(is_valid(track)) res.push_back(track);
    if(s==arr.size()) return;
    for(int i=s; i<arr.size(); ++i) {
        track.push_back(arr[i]);
        dfs(res, track, arr, i+1);
        track.pop_back();
    }
}

vector<int> helper(vector<int>& arr) {
    vector<vector<int>> res;
    vector<int> track;
    dfs(res, track, arr, 0);
    
    unordered_map<int, int> mp;
    int max_count = 0;
    for(auto& r : res) {
        for(int rr : r) {
            mp[rr]++;
            max_count = max(max_count, mp[rr]);
        }
    }
    vector<int> ans;
    for(auto& kv : mp) {
        if(kv.second == max_count) ans.push_back(kv.first);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr;
    for(int i=0; i<N; ++i){
        int a; cin >> a;
        arr.push_back(a);
    } 
    vector<int> ans = helper(arr);
    for(int i=0; i<ans.size()-1; ++i) {
        cout << ans[i] << ' ';
    }
    cout << ans.back() << endl;
    return 0;
}