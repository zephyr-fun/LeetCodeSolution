// 2022.05.02
// original
class Solution {
public:
    int cnt[10001];
    int deleteAndEarn(vector<int>& nums) {
        int size = nums.size();
        int maxv = 0;
        for(int i = 0; i < size; i++) {
            cnt[nums[i]]++;
            maxv = max(maxv, nums[i]); // key point
        }
        vector<vector<int>> dp(maxv + 1, vector<int>(2, 0));
        // dp[0][0] = 0; // 0 refers to not pick
        // dp[0][1] = 0; // 1 refers to pick
        for(int i = 1; i <= maxv; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + i * cnt[i]; // may there is not a i in nums, but with time cnt[i](which cnt[i] == 0), we jump the invalid state
        }
        return max(dp[maxv][0], dp[maxv][1]);
    }
};

// optim
// dp[i] refers to the max earn at position i
// 由于最终是求Math.max(f[max][0], f[max][1])，我们直接规定dp[i]=Math.max(f[i][0], f[i][1])
// 而f[i][0] = Math.max(f[i - 1][1], f[i - 1][0])，所以f[i][0]=dp[i-1]，
// 同理f[i - 1][0]= Math.max(f[i - 2][1], f[i - 2][0])=dp[i-2]， 再来看f[i][1] = f[i - 1][0] + i * cnts[i]，所以f[i][1] =dp[i-2]+ i * cnts[i]
// 最终动态规划状态转移方程为：dp[i]=Math.max(f[i][0], f[i][1])=Math.max(dp[i-1],dp[i-2]+ i * cnts[i])
class Solution {
public:
    int cnt[10001];
    int deleteAndEarn(vector<int>& nums) {
        int size = nums.size();
        int maxv = 0;
        for(int i = 0; i < size; i++) {
            cnt[nums[i]]++;
            maxv = max(maxv, nums[i]);
        }
        vector<int> dp(maxv + 1, 0);
        dp[1] = cnt[1]; // key point
        for(int i = 2; i <= maxv; i++) { // begin from 2
            dp[i] = max(dp[i - 1], dp[i - 2] + i * cnt[i]);
        }
        return dp[maxv];
    }
};

// 2022.05.08
class Solution {
public:
    int cnt[10001];
    int deleteAndEarn(vector<int>& nums) {
        int size = nums.size();
        int maxv = 0;
        for(int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
            maxv = max(maxv, nums[i]);
        }
        vector
    }
};