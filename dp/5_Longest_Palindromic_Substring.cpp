// 2022.07.18
// Manacher's Algorithm
class Solution {
public:
    string longestPalindrome(string s) {
        //insert '#'
        string t = "$#";
        for(int i = 0;i < s.size();i++)
        {
            t += s[i];
            t += "#";
        }
        //calculate p[]
        vector<int> p(t.size(), 0);
        // int p[t.size()] = {0};
        int mx = 0;
        int id = 0;
        int resLen = 0;
        int resCenter = 0;
        for(int i = 1; i < t.size(); i++)
        {
            p[i] = mx>i?min(p[2 * id - i],mx - i):1;
            //关于已经识别出来的回文长串的再利用，很精妙
            while(t[i + p[i]] == t[i - p[i]])
                p[i]++;
            if(mx < p[i]+i)
            {
                mx = i + p[i];
                id = i;
            }
            if(resLen < p[i])
            {
                resLen = p[i];
                resCenter = i;
            }
        }
        return s.substr((resCenter - resLen)/2 , resLen - 1);
    }
};

// plain dp
class Solution {
public:
    string longestPalindrome(string s) {
        int left = -1;
        int maxLen = -1;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // dp[i][j] if s[i] -> s[j] is a Palindrome
        for(int j = 0; j < n; j++) {
            for(int i = j; i >= 0; i--) {
                if(i == j) {
                    dp[i][j] = true;
                }
                else if(j - i == 1) {
                    if(s[i] == s[j]) {
                        dp[i][j] = true;
                    }
                }
                else {
                    if(s[i] == s[j]) {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if(dp[i][j] && (j - i + 1 > maxLen)) {
                    maxLen = j - i + 1;
                    left = i;
                }
            }
        }
        return s.substr(left, maxLen);
    }
};