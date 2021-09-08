#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int vv, int s) {
    if(s == 0 && vv==adj.size()) return true;
    visited[s] = true;
    vv++;
    for(int i=0; i<adj[s].size(); ++i) {
        if(adj[s][i] && (!visited[i] || i==0)) {
            if(dfs(adj, visited, vv, i)) return true;
        }
    }
    return false;
}

bool helper(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    return dfs(adj, visited, 0, 0);
}

int main() {
    int T;
    cin >> T;
    for(int t=0; t<T; ++t) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n, vector<int>(n, 0));
        for(int i=0; i<m; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a-1][b-1] = 1;
            adj[b-1][a-1] = 1;
        }
        if(helper(adj)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}