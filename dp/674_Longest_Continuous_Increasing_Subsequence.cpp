// 2022.04.13
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1]){
                dp[i] = dp[i - 1] + 1;
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};

// 2022.09.02
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 1;
        int res = 1;
        while(right < n) {
            while(right < n && nums[right] > nums[right - 1]) {
                right++;
            }
            // cout << left << right << endl;
            res = max(res, right - left);
            left = right;
            right++;
        }
        return res;
    }
};