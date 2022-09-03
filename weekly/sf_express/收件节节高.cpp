// 2022.06.19
class Solution {
public:
    int findMaxCI(vector<int>& nums) {
        int n = nums.size();
        int maxVal = 1;
        int cur = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                cur++;
                if(cur > maxVal) {
                    maxVal = cur;
                }
            }
            else {
                cur = 1;
            }
        }
        return maxVal;
    }
};