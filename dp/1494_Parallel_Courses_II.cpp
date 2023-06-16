// 2023.06.16
// endlesscheng version
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>> &relations, int k) {
        int pre1[n];
        memset(pre1, 0, sizeof(pre1));
        for (auto &r: relations)
            pre1[r[1] - 1] |= 1 << (r[0] - 1); // r[1] 的先修课程集合，下标改从 0 开始

        int u = (1 << n) - 1; // 全集
        int memo[1 << n];
        memset(memo, -1, sizeof(memo)); // -1 表示没有计算过
        function<int(int)> dfs = [&](int i) -> int {
            if (i == 0) return 0; // 空集
            int &res = memo[i]; // 注意这里是引用
            if (res != -1) return res; // 之前算过了
            int i1 = 0, ci = u ^ i; // i 的补集
            for (int j = 0; j < n; j++)
                if (i >> j & 1 && (pre1[j] | ci) == ci) // pre1[j] 在 i 的补集中
                    i1 |= 1 << j;
            if (__builtin_popcount(i1) <= k)  // 如果个数小于 k，则可以全部学习，不再枚举子集
                return dfs(i ^ i1) + 1;
            res = INT_MAX;
            for (int j = i1; j; j = (j - 1) & i1) // 枚举 i1 的子集 j
                if (__builtin_popcount(j) <= k)
                    res = min(res, dfs(i ^ j) + 1);
            return res;
        };
        return dfs(u);
    }
};