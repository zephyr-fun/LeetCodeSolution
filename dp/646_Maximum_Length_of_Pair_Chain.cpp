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

// 2023.02.09
// LIS optim
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        int len = 0;
        sort(pairs.begin(), pairs.end(), [] (vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        vector<int> dp(n + 7, -0x3f3f3f3f); // note pairs[i] -> [-1000, 1000]
        for(int i = 0; i < n; i++) {
            if(pairs[i][0] > dp[len]) {
                len++;
                dp[len] = pairs[i][1];
            }
            else {
                int left = 0;
                int right = len - 1;
                int pos = 0;
                while(left <= right) {
                    int mid = (left + right) >> 1;
                    if(dp[mid] >= pairs[i][0]) {
                        right = mid - 1;
                    }
                    else {
                        pos = mid;
                        left = mid + 1;
                    }
                }
                dp[pos + 1] = min(dp[pos + 1], pairs[i][1]);
            }
        }
        return len;
    }
};