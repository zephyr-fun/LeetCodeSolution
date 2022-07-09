// 2022.07.09
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> graph;
    int n;
    void dfs(int u) {
        if(u == n - 1) {
            res.emplace_back(path);
            return ;
        }
        for(auto v : graph[u]) {
            path.emplace_back(v);
            dfs(v);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph_) {
        graph = graph_;
        n = graph.size();
        path.emplace_back(0);
        dfs(0);
        return res;
    }
};