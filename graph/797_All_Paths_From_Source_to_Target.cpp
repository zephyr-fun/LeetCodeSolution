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

// 2022.07.25
class Solution {
public:
    int n;
    vector<vector<int>> g;
    vector<int> path;
    vector<vector<int>> res;
    void dfs(int u) {
        if(u == n - 1) {
            res.emplace_back(path);
            return ;
        }
        for(int i = 0; i < g[u].size(); i++) {
            path.emplace_back(g[u][i]);
            dfs(g[u][i]);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        g = graph;
        n = g.size();
        path.emplace_back(0);
        dfs(0);
        return res;
    }
};