#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int>& ws, int m) {
    for (int w : ws) {
        while (w > m) w -= m;
        if (w == m) return 1;
    }
    vector<int> dp(m + 1, 2001);
    dp[0] = 0;
    for (int w : ws) {
        for (int j = m; j >= 1; --j) {
            if (j - w >= 0) dp[j] = min(dp[j], dp[j - w] + 1);
        }
    }
    return dp[m] > 2000 ? -1 : dp[m];
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n, m;
        cin >> n;
        cin >> m;
        vector<int> w(n);
        for (int i = 0; i < n; ++i) cin >> w[i];
        cout << solve(w, m);
        if (t < T - 1) cout << endl;
    }
    return 0;
}