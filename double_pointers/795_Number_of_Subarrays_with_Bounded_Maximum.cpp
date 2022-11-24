// 2022.11.24
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int res = 0;
        int i0 = -1;
        int i1 = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] > right) {
                i0 = i;
            }
            if(nums[i] >= left) {
                i1 = i;
            }
            res += i1 - i0;
        }
        return res;
    }
};