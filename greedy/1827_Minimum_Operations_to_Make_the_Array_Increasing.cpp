// 2022.12.11
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cur = nums[0];
        int res = 0;
        for(int i = 1; i < n; i++) {
            cur++;
            if(cur > nums[i]) {
                res += cur - nums[i];
            }
            else if(cur < nums[i]) {
                cur = nums[i];
            }
        }
        return res;
    }
};