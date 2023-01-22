// 2023.01.22
class Solution {
    int m;
    vector<int> val;
    unordered_map<int, int> cache;

    int dfs(int mask) {
        if (cache.count(mask)) return cache[mask];
        int res = 0, left = mask >> 20, msk = mask & ((1 << 20) - 1);
        for (int i = 0, j = 0; i < val.size(); ++i, j += 5) // 枚举顾客
            if (msk >> j & 31) // cnt[val[i]] > 0
                res = max(res, (left == 0) + dfs((left + val[i]) % m << 20 | msk - (1 << j)));
        return cache[mask] = res;
    }

public:
    int maxHappyGroups(int batchSize, vector<int> &groups) {
        m = batchSize;
        int ans = 0;
        vector<int> cnt(m);
        for (int x: groups) {
            x %= m;
            if (x == 0) ++ans; // 直接排在最前面
            else if (cnt[m - x]) {
                --cnt[m - x]; // 配对
                ++ans;
            } else ++cnt[x];
        }

        int mask = 0;
        for (int x = 1; x < m; ++x)
            if (cnt[x]) {
                val.push_back(x);
                mask = mask << 5 | cnt[x];
            }
        // 上面加入 val 的顺序和拼接 mask 的顺序是相反的，reverse 后就对上了
        reverse(val.begin(), val.end());

        return ans + dfs(mask);
    }
};