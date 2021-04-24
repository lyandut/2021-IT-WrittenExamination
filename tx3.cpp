#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int>& arr) {
    int res = 0;
    if (arr.size() % 2) {
        int count = 0;
        for (int i = 0; i < arr.size(); i += 2) {
            if (i == arr.size() - 1) res += arr[i];
            else {
                res += arr[i + 1];
                count++;
            }
        }
        for (int i = 0; i < count; ++i) res += arr[i];
    }
    else {
        int count = 0;
        for (int i = 0; i < arr.size(); i += 2) {
            res += arr[i + 1];
            count++;
        }
        for (int i = 0; i < count; ++i) res += arr[i];
        res += arr[count - 1];
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) cin >> arr[i];
        sort(arr.begin(), arr.end());
        cout << solve(arr);
        if (t < T - 1) cout << endl;
    }
    return 0;
}