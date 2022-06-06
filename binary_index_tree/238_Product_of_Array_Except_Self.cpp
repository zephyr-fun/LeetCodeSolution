// 2022.06.06
// O(n), with two prefix multiply
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ms1(n + 7, 0);
        vector<int> ms2(n + 7, 0);
        ms1[0] = 1;
        ms2[n + 1] = 1;
        for(int i = 1; i <= n; i++) {
            ms1[i] = ms1[i - 1] * nums[i - 1];
        }
        for(int i = n; i >= 1; i--) {
            ms2[i] = ms2[i + 1] * nums[i - 1];
        }
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++) {
            res[i] = ms1[i] * ms2[i + 2];
        }
        return res;
    }
};