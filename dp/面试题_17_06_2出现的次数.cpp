// 2023.03.20
// endlesscheng version modify the template
class Solution {
public:
    int numberOf2sInRange(int n) {
        string s = to_string(n);
        int m = s.size();
        int dp[m][m];
        memset(dp, -1, sizeof(dp));
        function<int(int, int, bool)> dfs = [&] (int i, int cnt, bool is_limit) {
            if(i == m) {
                return cnt;
            }
            if(!is_limit && dp[i][cnt] != -1) {
                return dp[i][cnt];
            }
            int res = 0;
            int up = is_limit ? s[i] - '0' : 9;
            for(int d = 0; d <= up; d++) {
                res += dfs(i + 1, cnt + (d == 2), is_limit && d == up);
            }
            if(!is_limit) {
                dp[i][cnt] = res;
            }
            return res;
        };
        return dfs(0, 0, true);
    }
};