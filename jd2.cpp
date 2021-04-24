#include <iostream>
#include <vector>

using namespace std;

class UF
{
public:
    UF(int n) : _count(n), _size(n, 1), _parent(n)
    {
        for (int i = 0; i < n; ++i)
            _parent[i] = i;
    }

    void unionn(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return;
        if (_size[rootP] > _size[rootQ])
        {
            _parent[rootQ] = rootP;
            _size[rootP] += _size[rootQ];
        }
        else
        {
            _parent[rootP] = rootQ;
            _size[rootQ] += _size[rootP];
        }
        --_count;
    }

    bool connected(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }

    int find(int p)
    {
        while (p != _parent[p])
        {
            _parent[p] = _parent[_parent[p]];
            p = _parent[p];
        }
        return p;
    }

public:
    int _count;
    vector<int> _parent;
    vector<int> _size;
};

bool is_valid(int r, int c, vector<vector<int>>& arr) {
    bool a=false;
    bool b=false;
    bool cc=false;
    bool d=false;
    for(int i=r-1; i>=0; --i) 
        if(arr[i][c]>arr[r][c]) {
            a=true;
            break;
        }
    for(int i=r+1; i<arr.size(); ++i) 
        if(arr[i][c]>arr[r][c]) {
            b=true;
            break;
        }
    for(int j=c-1; j>=0; --j)
        if(arr[r][j]>arr[r][c]) {
            cc=true;
            break;
        }
    for(int j=c+1; j<arr[0].size(); ++j)
        if(arr[r][j]>arr[r][c]) {
            d=true;
            break;
        }
    return (a&&b&&cc&&d);
}

int func(vector<vector<int>>& arr) {
    int res = 0;
    int m=arr.size(), n=arr[0].size();
    if(m<3 || n<3) return 0;
    vector<vector<bool>> dp(m, vector<bool>(n, false));
    for(int i=1; i<=m-2; ++i) {
        for(int j=1; j<=n-2; ++j) {
            if(is_valid(i, j, arr)) dp[i][j] = true;
            // if(dp[i][j] && !dp[i-1][j] && !dp[i][j-1]) {
            //     res++;
            // }
        }
    }
    UF uf(m*n+1);
    int dummy = m*n;
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            if(!dp[i][j]) uf.unionn(i*n+j, dummy);
        }
    }
    for(int i=1; i<=m-2; ++i) {
        for(int j=1; j<=n-2; ++j) {
            if(dp[i][j] && dp[i-1][j]) uf.unionn(i*n+j, (i-1)*n+j);
            if(dp[i][j] && dp[i][j-1]) uf.unionn(i*n+j, i*n+j-1);
        }
    }
    res = uf._count-1;
    return res;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> arr[i][j];
        }
    }
    cout << func(arr) << endl;
    return 0;
}