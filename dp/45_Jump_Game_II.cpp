// 2022.04.06
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        int curCover = 0;
        int nextCover = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            nextCover = max(i + nums[i], nextCover);
            if(i == curCover){
                if(curCover != nums.size() - 1){
                    res++;
                    curCover = nextCover;
                    if(nextCover >= nums.size() - 1){
                        break;
                    }
                }
                else{
                    break;
                }
            }
        }
        return res;
    }
};

// 
class Solution {
public:
    int jump(vector<int>& nums) {
        int curCover = 0;
        int nextCover = 0;
        int res = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            nextCover = max(i + nums[i], nextCover);
            if(i == curCover){
                res++;
                curCover = nextCover;
            }
        }
        return res;
    }
};

// 2022.07.01
// plain dp
// slow
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        // dp[i] refers to start from i, the minimum step to get to the end
        vector<int> dp(n, 0);
        for(int i = n - 2; i >= 0; i--) {
            int cur = 0x3f3f3f3f;
            for(int j = i + 1; j < n && j <= i + nums[i]; j++) {
                cur = min(cur, dp[j]);
            }
            dp[i] = cur + 1;
        }
        return dp[0];
    }
};

// path dp
// old idea, same as above
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0x3f3f3f3f);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            int j = i + 1;
            while(j <= i + nums[i] && j < n) {
                dp[j] = min(dp[j], dp[i] + 1);
                j++;
            }
        }
        return dp[n - 1];
    }
};

// O(n), holy, dp + double pointer + greedy
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        for(int i = 1, j = 0; i < n; i++) {
            while(j + nums[j] < i) {
                j++;
            }
            dp[i] = dp[j] + 1;
        }
        return dp[n - 1];
    }
};