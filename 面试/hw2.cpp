#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/* 全排列 */

void dfs(vector<vector<int>>& res, vector<int>& track, 
         unordered_set<int>& visited, vector<int>& nums) {
    if(track.size()==nums.size()) {
        res.push_back(track);
        return;
    }

    for(int num : nums) {
        if(visited.count(num)) continue;
        track.push_back(num);
        visited.insert(num);
        dfs(res, track, visited, nums);
        track.pop_back();
        visited.erase(num);
    }
}

vector<vector<int>> func2(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> track;
    unordered_set<int> visited;
    dfs(res, track, visited, nums);
    return res;
}


int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = func2(nums);
    for(auto& each : res) {
        for(int num : each) cout << num << " ";
        cout << endl;
    }
    return 0;
}