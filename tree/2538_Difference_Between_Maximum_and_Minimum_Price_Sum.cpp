// 2023.03.13
// https://leetcode.cn/problems/difference-between-maximum-and-minimum-price-sum/solution/by-endlesscheng-5l70/
// https://www.bilibili.com/video/BV1QT41127kJ/?vd_source=1e5e0fe23d3d704a3f15a4928671d9ac
class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> g(n);
        for(auto& edge : edges) {
            g[edge[0]].emplace_back(edge[1]);
            g[edge[1]].emplace_back(edge[0]);
        }
        long res = 0;
        function<pair<long, long>(int, int)> dfs = [&] (int u, int parent) -> pair<long, long> {
            long p = price[u];
            long max_s1 = p;
            long max_s2 = 0;
            for(auto& v : g[u]) {
                if(v == parent) {
                    continue;
                }
                auto [s1, s2] = dfs(v, u);
                res = max(res, max(max_s1 + s2, max_s2 + s1));
                max_s1 = max(max_s1, s1 + p);
                max_s2 = max(max_s2, s2 + p);
            }
            return {max_s1, max_s2};
        };
        dfs(0, -1);
        return res;
    }
};