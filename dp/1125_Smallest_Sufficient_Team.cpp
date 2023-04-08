// 2023.04.08
// https://leetcode.cn/problems/smallest-sufficient-team/solution/zhuang-ya-0-1-bei-bao-cha-biao-fa-vs-shu-qode/
// dfs with memo
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people) {
        unordered_map<string, int> sid;
        int m = req_skills.size();
        for(int i = 0; i < m; i++) {
            sid[req_skills[i]] = i;
        }
        int n = people.size();
        int mask[n];
        memset(mask, 0, sizeof(mask));
        for(int i = 0; i < n; ++i) {
            for(auto &s: people[i]) {
                mask[i] |= 1 << sid[s];
            }   
        }
        int u = 1 << m;
        long long memo[n][u];
        long long all = (1LL << n) - 1; // 神奇的是，当把all的数据类型换为int时，将超时
        memset(memo, -1, sizeof(memo));
        function<long long(int, int)> dfs = [&] (int i, int j) -> long long {
            if(j == 0) {
                return 0; // 背包已装满
            }
            if(i < 0) {
                return all; // 没法装满背包，返回全集，这样下面比较集合大小会取更小的
            }
            auto &res = memo[i][j];
            if(res != -1) {
                return res;
            }
            auto r1 = dfs(i - 1, j); // no pick mask[i]
            auto r2 = dfs(i - 1, j & ~mask[i]) | (1LL << i); // pick mask[i]
            return res = __builtin_popcountll(r1) < __builtin_popcountll(r2) ? r1 : r2;
        };
        auto t = dfs(n - 1, u - 1);
        vector<int> res;
        for (int i = 0; i < n; ++i)
            if ((t >> i) & 1)
                res.push_back(i);
        return res;
    }
};