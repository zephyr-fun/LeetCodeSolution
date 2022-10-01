// 2022.09.25
// TLE
class Solution {
public:
    vector<int> vals;
    vector<vector<int>> tree;
    int res = 0;
    void dfs(int idx, int parent, int up) {
        if(vals[idx] == up) {
            res++;
        }
        for(auto& next : tree[idx]) {
            if(next == parent) {
                continue;
            }
            if(vals[next] > up) {
                continue;
            }
            dfs(next, idx, up);
        }
    }
    int numberOfGoodPaths(vector<int>& vals_, vector<vector<int>>& edges) {
        vals = vals_;
        int n = vals.size();
        tree.resize(n, vector<int>());
        for(auto& edge : edges) {
            tree[edge[0]].emplace_back(edge[1]);
            tree[edge[1]].emplace_back(edge[0]);
        }
        for(int i = 0; i < n; i++) {
            dfs(i, -1, vals[i]);
        }
        return (res - n) / 2 + n;
    }
};

// union find set
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> time(n, vector<int>(2, 0));
    for(int i = 0; i < n; i++) {
        cin >> time[i][0] >> time[i][1];
    }
    sort()
}