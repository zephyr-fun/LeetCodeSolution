// 2022.11.23
// greedy sort + dp
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](auto& a, auto& b) {
            if(a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        int n = pairs.size();
        int res = 1;
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = i - 1; j >= 0 && dp[i] == 1; j--) {
                if(pairs[i][0] > pairs[j][1]) {
                    dp[i] = dp[j] + 1;
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

// LIS optim
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](auto& a, auto& b) {
            if(a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        int n = pairs.size();
        int res = 1;
        vector<int> dp(n + 7, 0x3f3f3f3f);
        for(int i = 0; i < n; i++) {
            int l = 1;
            int r = i + 1;
            while(l < r) {
                int mid = (l + r) >> 1;
                if(dp[mid] >= pairs[i][0]) {
                    r = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            dp[r] = min(dp[r], pairs[i][1]);
            res = max(res, r);
        }
        return res;
    }
};