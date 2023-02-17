// 2022.10.24
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = nums[0];
        right[n - 1] = 0x3f3f3f3f;
        for(int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], nums[i - 1]);
            right[n - i - 1] = min(right[n - i], nums[n - i]);
        }
        for(int i = 0; i < n; i++) {
            if(left[i] <= right[i]) {
                return i + 1;
            }
        }
        return -1;
    }
};