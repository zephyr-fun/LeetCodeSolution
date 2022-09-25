// 2022.09.25
// 数位DP
int diffs[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
class Solution {
public:
    int rotatedDigits(int n) {
        string s = to_string(n);
        int m = s.size();
        int dp[m][2];
        memset(dp, -1, sizeof(dp));
        function<int (int, bool, bool)> f = [&] (int idx, bool has_diff, bool is_limit) -> int {
            if(idx == m) {
                return has_diff;
            }
            if(!is_limit && dp[idx][has_diff] >= 0) {
                return dp[idx][has_diff];
            }
            int res = 0;
            int up = is_limit ? s[idx] - '0' : 9;
            for(int d = 0; d <= up; d++) {
                if(diffs[d] != -1) {
                    res += f(idx + 1, has_diff || diffs[d], is_limit && d == up);
                }
            }
            if(!is_limit) {
                dp[idx][has_diff] = res;
            }
            return res;
        };
        return f(0, false, true);
    }
};