// 2023.03.13
// https://leetcode.cn/problems/longest-path-with-different-adjacent-characters/solution/by-endlesscheng-92fw/
class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> g(n);
        for(int i = 1; i < n; i++) {
            g[parent[i]].emplace_back(i); // 并不记录为双向图，因为在计算当前节点时，如果需要回到加入走父节点的路径，那么可通过“在当前节点为父节点”时求出
        }
        int res = 0;
        function<int(int)> dfs = [&] (int u) {
            int maxLen = 0;
            for(auto& v : g[u]) {
                int len = dfs(v) + 1;
                if(s[u] != s[v]) {
                    res = max(res, maxLen + len);
                    maxLen = max(maxLen, len);
                }
            }
            return maxLen;
        };
        dfs(0);
        return res + 1;
    }
};