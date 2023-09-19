// 2023.09.19
class Solution {
public:
    bool check(vector<int> &nums, int k, int mx) {
        int f0 = 0;
        int f1 = 0;
        for (int x : nums) {
            if (x > mx) {
                f0 = f1;
            }
            else {
                int temp = f1;
                f1 = max(f1, f0 + 1);
                f0 = temp;
            }
        }
        return f1 >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int left = 0;
        int right = *max_element(nums.begin(), nums.end());
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            (check(nums, k, mid) ? right : left) = mid;
        }
        return right;
    }
};