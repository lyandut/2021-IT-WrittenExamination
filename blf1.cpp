#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
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

int main() {
    string str;
    cin >> str;
    vector<string> res1 = split(str, ',');
    unordered_map<int, string> mp1, mp2;
    int id;
    char ch;
    string val;
    for(string &s : res1) {
        stringstream ss(s);
        ss >> id >> ch >> val;
        mp1[id] = val;
    }
    str.clear();
    cin >> str;
    res1 = split(str, ',');
    for(string &s : res1) {
        stringstream ss(s);
        ss >> id >> ch >> val;
        mp2[id] = val;
    }
    vector<string> res;
    // add
    for(auto &each : mp2) {
        if(!mp1.count(each.first))
            res.emplace_back("add-"+to_string(each.first));
        else if(mp2[each.first] != mp1[each.first])
            res.emplace_back("modify-"+to_string(each.first));
    }
    // del
    for(auto &each : mp1) {
        if(!mp2.count(each.first))
            res.emplace_back("delete-"+to_string(each.first));
        //else if(mp2[each.first] != mp1[each.first])
        //    res.emplace_back("modify-"+to_string(each.first));
    }
    sort(res.begin(), res.end());
    for(int i=0; i<res.size()-1; ++i) {
        cout << res[i] << ",";
    }
    cout << res.back()<<endl;
    return 0;
}