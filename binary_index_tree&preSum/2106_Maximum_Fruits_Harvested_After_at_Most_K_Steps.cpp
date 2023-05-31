// 2022.09.11
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> sum(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + fruits[i - 1][1];
        }
        vector<int> pos(n, 0);
        for(int i = 0; i < n; i++) {
            pos[i] = fruits[i][0];
        }
        // [l, r]
        int res = 0;
        for(int x = k; x >= 0; x--) {
            int y = (k - x) / 2;
            int l = startPos - x;
            int r = startPos + y;
            auto pl = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            auto pr = upper_bound(pos.begin(), pos.end(), r) - pos.begin();
            res = max(res, sum[pr] - sum[pl]);
            l = startPos - y;
            r = startPos + x;
            pl = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            pr = upper_bound(pos.begin(), pos.end(), r) - pos.begin();
            res = max(res, sum[pr] - sum[pl]);
        }
        return res;
    }
};

// binary search
class Solution {
public:
    int lower(int left, int right, vector<int>& nums, int target) {
        int pos = -1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] < target) {
                pos = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return pos;
    }
    int upper(int left, int right, vector<int>& nums, int target) {
        int pos = -1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] <= target) {
                pos = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return pos;
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> sum(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + fruits[i - 1][1];
        }
        vector<int> pos(n, 0);
        for(int i = 0; i < n; i++) {
            pos[i] = fruits[i][0];
        }
        // [l, r]
        int res = 0;
        for(int x = k; x >= 0; x--) {
            int y = (k - x) / 2;
            // cout << "xy:" << x << y << endl;
            int l = startPos - x;
            int r = startPos + y;
            auto pl = lower(0, n - 1, pos, l);
            auto pr = upper(0, n - 1, pos, r);
            // cout << "lr:" << l << r << endl;
            // cout << "plr:" << pl << pr << endl;
            // cout << "sum:" << sum[pr + 1] - sum[pl + 1] << endl;
            res = max(res, sum[pr + 1] - sum[pl + 1]);
            l = startPos - y;
            r = startPos + x;
            pl = lower(0, n - 1, pos, l);
            pr = upper(0, n - 1, pos, r);
            // cout << "lr:" << l << r << endl;
            // cout << "plr:" << pl << pr << endl;
            // cout << "sum:" << sum[pr + 1] - sum[pl + 1] << endl;
            res = max(res, sum[pr + 1] - sum[pl + 1]);
        }
        return res;
    }
};

// 2023.05.31
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int left = lower_bound(fruits.begin(), fruits.end(), startPos - k, [](const auto& a, int b) {
            return a[0] < b;
        }) - fruits.begin();
        int right = left;
        int s = 0;
        int n = fruits.size();
        for(; right < n && fruits[right][0] <= startPos; right++) {
            s += fruits[right][1];
        }
        int res = s;
        for(; right < n && fruits[right][0] <= startPos + k; right++) {
            s += fruits[right][1];
            while(fruits[right][0] * 2 - fruits[left][0] - startPos > k && fruits[right][0] + startPos - fruits[left][0] * 2 > k) {
                s -= fruits[left++][1];
            }
            res = max(res, s);
        }
        return res;
    }
};