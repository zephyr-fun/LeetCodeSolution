// 2022.08.06 contest 2022.08.15 update
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long res = 0;
        int m = nums.back();
        for(int i = nums.size() - 2; i >= 0; i--) {
            int k = (nums[i] - 1) / m;
            res += k;
            m = nums[i] / (k + 1);
        }
        return res;
    }
};