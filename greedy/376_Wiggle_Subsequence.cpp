// 2022.04.06
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums.size();
        }
        int curDiff = 0;
        int preDiff = 0;
        int res = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            curDiff = nums[i + 1] - nums[i];
            if(preDiff <= 0 && curDiff > 0 || preDiff >= 0 && curDiff < 0){
                res++;
                preDiff = curDiff;
            }
        }
        return res;
    }
};

// dp
class Solution {
public:
    int dp[1005][2];
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp, 0, sizeof dp);
        dp[0][0] = dp[0][1] = 1;
        for(int i = 1; i < nums.size(); i++){
            dp[i][0] = dp[i][1] = 1;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }
            }
            for(int j = 0; j < i; j++){
                if(nums[i] < nums[j]){
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }
            }
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};