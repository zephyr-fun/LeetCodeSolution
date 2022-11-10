// 2022.11.10
// same as LCS, but with a auxiliary g[i]
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1);
        vector<int> g(n, 1);
        int maxVal = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    if(f[i] < f[j] + 1) {
                        f[i] = f[j] + 1;
                        g[i] = g[j];
                    }
                    else if(f[i] == f[j] + 1) {
                        g[i] += g[j];
                    }
                }
            }
            maxVal = max(maxVal, f[i]);
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(f[i] == maxVal) {
                res += g[i];
            }
        }
        return res;
    }
};

// fenwick tree
class FenwickTree {
public:
    FenwickTree(int n_) : n(n_), tr(n_ + 7, vector<int>(2, 0)) {};

    void update(int idx, vector<int> info) {
        while(idx <= n) {
            int len = tr[idx][0];
            int cnt = tr[idx][1];
            if(len == info[0]) {
                cnt += info[1];
            }
            else if(len < info[0]) {
                len = info[0];
                cnt = info[1];
            }
            tr[idx][0] = len;
            tr[idx][1] = cnt;
            idx += lowbit(idx);
        }
    }

    vector<int> query(int idx) {
        int len = 0;
        int cnt = 0;
        while(idx > 0) {
            if(len == tr[idx][0]) {
                cnt += tr[idx][1];
            }
            else if(len < tr[idx][0]) {
                len = tr[idx][0];
                cnt = tr[idx][1];
            }
            idx -= lowbit(idx);
        }
        return {len, cnt};
    }

private:
    static inline int lowbit(int x) {
        return x & (-x);
    }
    int n;
    vector<vector<int>> tr;
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n, 0);
        for(int i = 0; i < n; i++) {
            temp[i] = nums[i];
        }
        sort(temp.begin(), temp.end());
        unordered_map<int, int> map;
        for(int i = 0, idx = 1; i < n; i++) {
            if(!map.count(temp[i])) {
                map[temp[i]] = idx;
                idx++;
            }
        }
        FenwickTree tree(n);
        for(int i = 0; i < n; i++) {
            int x = map[nums[i]];
            auto info = tree.query(x - 1);
            int len = info[0];
            int cnt = info[1];
            tree.update(x, {len + 1, max(cnt, 1)});
        }
        auto res = tree.query(n);
        return res[1];
    }
};