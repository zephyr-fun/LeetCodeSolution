// 2022.08.07 contest 2022.08.15 update
class Solution {
public:
    vector<vector<int>> tree;
    unordered_set<int> r;
    int res = 0;
    void dfs(int cur, int parent) {
        res++;
        for(auto child : tree[cur]) {
            if(r.count(child) || child == parent) {
                continue;
            }
            dfs(child, cur);
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        for(auto re : restricted) {
            r.insert(re);
        }
        tree.resize(n);
        for(auto edge : edges) {
            // sort(edge.begin(), edge.end());
            tree[edge[1]].emplace_back(edge[0]);
            tree[edge[0]].emplace_back(edge[1]);
        }
        dfs(0, -1);
        return res;
    }
};