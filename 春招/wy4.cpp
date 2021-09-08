#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int is_valid(vector<int>& track, int old_sum) {
    int sum = 0;
    for(int t : track) sum += t;
    if(sum % 6 == 0 && sum > old_sum) return sum;
    return -1;
}

void dfs(vector<int>& res, vector<int>& track, int &sum, vector<int>& arr, int s) {
    int new_sum = is_valid(track, sum);
    if(new_sum != -1) {
        sum = new_sum;
        res = track;
    }
    if(s==arr.size()) return;
    for(int i=s; i<arr.size(); ++i) {
        track.push_back(arr[i]);
        dfs(res, track, sum, arr, i+1);
        track.pop_back();
    }
}

int helper(vector<int>& arr) {
    vector<int> res;
    int sum = -1;
    vector<int> track;
    dfs(res, track, sum, arr, 0);
    return sum==0 ? -1 : sum;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr;
    for(int i=0; i<N; ++i){
        int a; cin >> a;
        arr.push_back(a);
    } 
    cout << helper(arr) << endl;
    return 0;
}
