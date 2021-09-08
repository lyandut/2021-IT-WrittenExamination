#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> table(n, vector<int>(n));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> table[i][j];
        }
    }
    vector<int> dp(m+1);
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=m; ++i) {
        dp[i] = table[dp[i-1]-1][dp[i-2]-1];
    }
    cout << dp[m] << endl;
    return 0;
}