// 2022.11.11
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        str1 = " " + str1;
        str2 = " " + str2;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(str1[i] == str2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        string res = "";
        int i = n;
        int j = m;
        while(i > 0 || j > 0) {
            if(i == 0) {
                res += str2[j];
                j--;
            }
            else if(j == 0) {
                res += str1[i];
                i--;
            }
            else {
                if(str1[i] == str2[j]) {
                    res += str1[i];
                    i--;
                    j--;
                }
                else if(dp[i][j] == dp[i - 1][j]) {
                    res += str1[i];
                    i--;
                }
                else {
                    res += str2[j];
                    j--;
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// 2022.11.28
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        str1 = " " + str1;
        str2 = " " + str2;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(str1[i] == str2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        string res = "";
        int i = n;
        int j = m;
        while(i > 0 || j > 0) {
            if(i == 0) {
                res += str2[j];
                j--;
            }
            else if(j == 0) {
                res += str1[i];
                i--;
            }
            else {
                if(str1[i] == str2[j]) {
                    res += str1[i];
                    i--;
                    j--;
                }
                else if(dp[i][j] == dp[i - 1][j]) {
                    res += str1[i];
                    i--;
                }
                else {
                    res += str2[j];
                    j--;
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};