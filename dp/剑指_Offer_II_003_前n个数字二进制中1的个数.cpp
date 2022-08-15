// 2022.08.15
// plain
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i <= n; i++) {
            int temp = 0;
            int cur = i;
            while(cur) {
                if(cur & 1) {
                    temp++;
                }
                cur = cur >> 1;
            }
            res.emplace_back(temp);
        }
        return res;
    }
};

// dp optim
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};