#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
325. 和等于 k 的最长子数组长度
- 考点：前缀和
- 相似题目：
560. 和为K的子数组个数
525. 0 和 1 个数相同的子数组
523. 和为K倍数的子数组
*/

// 暴力，超时
int func(vector<int>& nums, int target) {
    vector<int> sums;
    sums.push_back(0);
    int sum = 0;
    for (int num : nums) {
        sum += num;
        sums.push_back(sum);
    }

    int max_len = 0;
    for (int i = 0; i < sums.size(); ++i) {
       for (int j = i + 1; j < sums.size(); ++j) {
           if (sums[j] - sums[i] == target) {
               max_len = max(max_len, j - i);
           }
       }
    }
    return max_len;
}

// hash
int maxSubArrayLen(vector<int>& nums, int k) {
    int max_len = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    int sum = 0;
    for(int i=0; i<nums.size(); ++i) {
        sum += nums[i];
        if(mp.count(sum-k)) max_len = max(max_len, i-mp[sum-k]);
        if(!mp.count(sum)) mp[sum] = i;
    }
    return max_len;
}


int main() {
    vector<int> nums = { 1,-1,5,-2,3 };
    cout << func(nums, 3) << endl;
    cout << maxSubArrayLen(nums, 3) << endl;
    return 0;
}