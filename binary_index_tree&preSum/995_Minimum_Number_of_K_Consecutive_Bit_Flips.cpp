// 2022.06.11
// use diff array to record operator number
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        int res = 0;
        for(int i = 0, opt = 0; i < n; i++) {
            opt += diff[i];
            if((nums[i] + opt) % 2 == 0) { // nums[i] refers to 0\1, opt 
                if(i + k > n) {
                    return -1;
                }
                diff[i + 1]++;
                diff[i + k]--;
                res++;
            }
        }
        return res;
    }
};