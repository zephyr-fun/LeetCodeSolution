// 2022.10.02
// dfs TLE
class Solution {
public:
    int res = 0;
    void dfs(string s, int cnt) {
        if(s == "") {
            res = max(res, cnt);
            return ;
        }
        bool flag = false;
        for(int i = 0; i < s.size() / 2; i++) {
            if(s.substr(0, i + 1) == s.substr(i + 1, i + 1)) {
                flag = true;
                dfs(s.substr(i + 1), cnt + 1);
            }
        }
        if(!flag) {
            dfs("", cnt + 1);
        }
    }
    int deleteString(string s) {
        dfs(s, 0);
        return res;
    }
};

// dp
typedef unsigned long long ULL;

const int N = 4007;
const int P = 131;

ULL h[N];
ULL p[N];

class Solution {
public:
    ULL get(int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    int deleteString(string s) {
        int n = s.size();
        p[0] = 1;
        for(int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * P;
            h[i] = h[i - 1] * P + s[i - 1];
        }

        vector<int> dp(n + 2);
        for(int i = n; i > 0; i--) {
            dp[i] = 1;
            // j means length
            for(int j = 1; j <= (n - i + 1) / 2; j++) {
                if(get(i, i + j - 1) == get(i + j, i + 2 * j - 1)) {
                    dp[i] = max(dp[i], dp[i + j] + 1);
                }
            }
        }
        return dp[1];
    }
};