#include <iostream> 
#include <vector>
using namespace std;

vector<vector<int>> func(vector<vector<int>>& vec, int n, int k) {
    vector<vector<int>> res(n*k, vector<int>(n*k));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            // vec[i][j]
            for(int k1=0; k1<k; ++k1) {
                for(int k2=0; k2<k; ++k2) {
                    res[i*k+k1][j*k+k2] = vec[i][j];
                }
            }
        }
    }
    return res;
}


int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> vec(n, vector<int>(n));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> vec[i][j];
        }
    }
    vector<vector<int>> res = func(vec, n, k);
    for(int i=0; i<n*k; ++i) {
        for(int j=0; j<n*k; ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}