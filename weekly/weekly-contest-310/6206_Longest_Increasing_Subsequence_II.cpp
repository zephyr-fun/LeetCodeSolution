// 2022.09.11
// frog version
class Solution {
    int mx;
    vector<int> maxo;

    // 查询区间 [ql, qr] 中的最大值
    int query(int id, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return maxo[id];
        else {
            int nxt = id << 1, mid = (l + r) >> 1;
            return max(ql <= mid ? query(nxt, l, mid, ql, qr) : 0, qr > mid ? query(nxt | 1, mid + 1, r, ql, qr) : 0);
        }
    }

    // 用 val 更新位置 pos 的最大值
    void modify(int id, int l, int r, int pos, int val) {
        if (l == r) maxo[id] = max(maxo[id], val);
        else {
            int nxt = id << 1, mid = (l + r) >> 1;
            if (pos <= mid) modify(nxt, l, mid, pos, val);
            else modify(nxt | 1, mid + 1, r, pos, val);
            maxo[id] = max(maxo[nxt], maxo[nxt | 1]);
        }
    }

public:
    int lengthOfLIS(vector<int>& nums, int k) {
        for (int x : nums) mx = max(mx, x);
        maxo.resize(mx * 4 + 10);
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            // 小心询问范围可能超过 [1, mx]，限制一下
            if (nums[i] == 1) x = 1;
            else x = query(1, 1, mx, max(1, nums[i] - k), nums[i] - 1) + 1;
            modify(1, 1, mx, nums[i], x);
            ans = max(ans, x);
        }
        return ans;
    }
};