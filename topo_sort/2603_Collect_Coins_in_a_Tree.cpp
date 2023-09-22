// 2023.09.21
class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        int edge_left = n - 1;
        vector<vector<int>> g(n);
        vector<int> d(n, 0);
        for (auto& edge : edges) {
            int x = edge[0];
            int y = edge[1];
            g[x].emplace_back(y);
            g[y].emplace_back(x);
            d[x]++;
            d[y]++;
        }
        queue<int> que;
        for (int i = 0; i < n; i++) {
            if (d[i] == 1 && coins[i] == 0) { // 没用的叶子节点
                que.push(i);
            }
        }
        while (!que.empty()) {
            edge_left--;
            int u = que.front();
            que.pop();
            for (auto& v : g[u]) {
                if (--d[v] == 1 && coins[v] == 0) {
                    que.push(v);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (d[i] == 1 && coins[i]) { // 有金币的叶子节点（两层以内的可以直接拿到）
                que.push(i);
            }
        }
        edge_left -= que.size(); // 减去一层距离为 2 的叶子节点
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (auto& v : g[u]) {
                if (--d[v] == 1) {
                    edge_left--;
                }
            }
        }
        return max(edge_left * 2, 0);
    }
};