// 2022.05.12
// TLE, 1e5, O(n*n), > 1e7
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // sort first dim
        sort(envelopes.begin(), envelopes.end());
        // search LIS on second dim
        // dp[i] refers to the maximum length with selecting envelopes[i][1]
        vector<int> dp(envelopes.size() + 1, 1);
        int res = 0;
        for(int i = 1; i <= envelopes.size(); i++) {
            for(int j = 1; j < i; j++) {
                if(envelopes[i - 1][1] > envelopes[j - 1][1] && envelopes[i - 1][0] > envelopes[j - 1][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

// optim O(nlogn)
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // sort first dim
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>&b) {
            if(a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        // search LIS on second dim
        // dp[len] refers to the minimum x required to compose a subsequence of length len
        vector<int> dp(envelopes.size() + 1, 0x3f3f3f3f);
        dp[1] = envelopes[0][1];
        int len = 1;
        for(int i = 1; i < envelopes.size(); i++) {
            if(envelopes[i][1] > dp[len]) {
                len++;
                dp[len] = envelopes[i][1];
            }
            else {
                int left = 1;
                int right = len;
                int pos = 0;
                while(left <= right) {
                    int mid = left + (right - left) / 2;
                    if(dp[mid] >= envelopes[i][1]) {
                        right = mid - 1;
                    }
                    else {
                        pos = mid;
                        left = mid + 1;
                    }
                }
                dp[pos + 1] = envelopes[i][1];
            }
        }
        return len;
    }
};

// 2022.05.20
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        // dp[len] refers to minimum number with len
        vector<int> dp(envelopes.size() + 1, 0);
        int len = 1;
        dp[len] = envelopes[0][1];
        for(int i = 1; i < envelopes.size(); i++) {
            if(envelopes[i][1] > dp[len]) {
                len++;
                dp[len] = envelopes[i][1];
            }
            else {
                int left = 1;
                int right = len;
                int pos = 0; // good good
                while(left <= right) {
                    int mid = left + (right - left) / 2;
                    if(dp[mid] >= envelopes[i][1]) {
                        right = mid - 1;
                    }
                    else {
                        pos = mid;
                        left = mid + 1;
                    }
                }
                dp[pos + 1] = envelopes[i][1];
            }
            // remember to comment debug code, so that O(nlogn) won't turn to O(n^2)
        }
        return len;
    }
};

// 2022.07.23
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>&b) {
            if(a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        int n = envelopes.size();
        vector<int> dp(n + 1);
        int len = 1;
        dp[len] = envelopes[0][1];
        for(int i = 1; i < n; i++) {
            if(dp[len] < envelopes[i][1]) {
                len++;
                dp[len] = envelopes[i][1];
            }
            else {
                int left = 1;
                int right = len;
                int pos = 0;
                while(left <= right) {
                    int mid = (left + right) >> 1;
                    if(dp[mid] < envelopes[i][1]) {
                        pos = mid;
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                dp[pos + 1] = envelopes[i][1]; // pos + 1
            }
        }
        return len;
    }
};