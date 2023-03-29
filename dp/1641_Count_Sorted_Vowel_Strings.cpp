// 2023.03.29
// 长度为 n 的状态最多只会遇到一次
// 这个解法的 dp 定义还需要再理解一下
class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp;
        dp.resize(n, vector<int>(5, 0));
        function<int(int, int)> traversal = [&] (int num, int idx) {
            if(num >= n) {
                return 1;
            }
            if(dp[num][idx]) {
                return dp[num][idx];
            }
            int res = 0;
            for(int k = idx; k < 5; k++) {
                res += traversal(num + 1, k);
            }
            return dp[num][idx] = res;
        };
        return traversal(0, 0);
    }
};

// dp[i][j] refers to len of i, ends with j
class Solution {
public:
    int countVowelStrings(int n) {
        int dp[5] = {1, 1, 1, 1, 1};
        for(int i = 0; i < n - 1; i++) {
            int s = 0; // prefix
            for(int j = 0; j < 5; j++) {
                s += dp[j];
                dp[j] = s;
            }
        }
        return accumulate(dp, dp + 5, 0);
    }
};