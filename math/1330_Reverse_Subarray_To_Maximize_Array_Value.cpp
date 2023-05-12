// 2023.05.12
// https://leetcode.cn/problems/reverse-subarray-to-maximize-array-value/solution/bu-hui-hua-jian-qing-kan-zhe-pythonjavac-c2s6/
// a = nums[i−1], b = nums[i], x = nums[j], y = nums[j+1]
// |a - b| = max(a, b) - min(a, b)
// a + b = max(a, b) + min(a, b)
// a + b + |a - b| = 2 max(a, b)
// a + b - |a - b| = 2 min(a, b)
class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int base = 0;
        int d = 0;
        int mx = INT_MIN;
        int mn = INT_MAX;
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            int a = nums[i - 1];
            int b = nums[i];
            base += abs(a - b);
            mx = max(mx, min(a, b));
            mn = min(mn, max(a, b));
            d = max(d, max(abs(nums[0] - b) - abs(a - b), abs(nums[n - 1] - a) - abs(a - b)));
        }
        return base + max(d, 2 * (mx - mn));
    }
};