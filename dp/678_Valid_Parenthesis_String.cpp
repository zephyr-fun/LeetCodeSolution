// 2022.09.16
class Solution {
public:
    bool checkValidString(string s) {
        int l = 0;
        int r = 0;
        for(auto& c : s) {
            if(c == '(') {
                l++;
                r++;
            }
            else if(c == ')') {
                l--;
                r--;
            }
            else {
                l--;
                r++;
            }
            l = max(l, 0); // key part
            if(l > r) {
                return false;
            }
        }
        return l == 0; // key part
    }
};

// dp
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= i; j++) {
                if(s[i - 1] == '(') {
                    if(j - 1 >= 0) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
                else if(s[i - 1] == ')') {
                    if(j + 1 <= i) {
                        dp[i][j] = dp[i - 1][j + 1];
                    }
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                    if(j - 1 >= 0) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j - 1];
                    }
                    if(j + 1 >= 0) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j + 1];
                    }
                }
            }
        }
        return dp[n][0];
    }
};

// 2022.12.14
// acwing yxc version
// https://www.acwing.com/video/2456/
// from stack to cnt
// from cnt to range [low, high]
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;
        for(auto& c : s) {
            if(c == '(') {
                low++;
                high++;
            }
            else if(c == ')') {
                low--;
                high--;
            }
            else {
                low--;
                high++;
            }
            low = max(low, 0);
            if(low > high) {
                return false;
            }
        }
        return low == 0;
    }
};