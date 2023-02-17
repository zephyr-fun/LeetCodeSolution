// 2023.01.28
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int le = 0;
        int ro = 0;
        int re = 0;
        for(int i = 0; i < n; i++) {
            if(i & 1) {
                ro += nums[i];
            }
            else {
                re += nums[i];
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(i & 1) {
                ro -= nums[i];
            }
            else {
                re -= nums[i];
            }
            if(lo + re == le + ro) {
                res++;
            }
            if(i & 1) {
                lo += nums[i];
            }
            else {
                le += nums[i];
            }
        }
        return res;
    }
};