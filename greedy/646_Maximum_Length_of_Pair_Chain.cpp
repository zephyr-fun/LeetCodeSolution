// 2022.09.03
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int res = 1;
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
            if(a[1] == b[1]) {
                return a[0] > b[0]; // 右端点一样，左边由小到大的话，会导致[10, 13], [11, 13]这样的区间重复计数两次
            }
            return a[1] < b[1];
        });
        int n = pairs.size();
        int prev = pairs[0][1];
        for(int i = 1; i < n; i++) {
            if(pairs[i][0] > prev) {
                res++;
                prev = pairs[i][1];
            }
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