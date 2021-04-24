#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <queue>
using namespace std;

vector<string> split(string &str, char deli) {
    vector<string> res;
    stringstream ss(str);
    string tmp;
    while(getline(ss, tmp, deli)) {
        res.push_back(tmp);
    }
    return res;
} 

int bfs(vector<vector<int>>& board) {
    if(board.empty()) return 0;
    int m=board.size(), n=board.size();
    if(board[0][0]==0 || board[m-1][n-1]==0)return 0;
    queue<pair<int, int>> q;
    q.push({0,0});
    int res = 1;
    vector<vector<int>> dirs = {{0,1}, {1,0}};
    while(!q.empty()) {
        int sz = q.size();
        for(int i=0; i<sz; ++i) {
            auto cur = q.front(); q.pop();
        	if(cur.first==m-1 && cur.second==n-1) return res;
            for(auto& d : dirs) {
                int x=cur.first+d[0], y=cur.second+d[1];
                if(x>=0 && x<m && y>=0 && y<n && board[x][y]) q.push({x,y});
            }
        }
        res++;
    }
	return res;
}

int main() {
    string str; cin >> str;
    vector<string> strs = split(str, ';');
    vector<vector<int>> board;
    for(string& s : strs) {
        board.push_back({});
        vector<string> tmp = split(s, ',');
        for(string& t : tmp) board.back().push_back(stoi(t));
    }
    cout << bfs(board) << endl;
    return 0;
}