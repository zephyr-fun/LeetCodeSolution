// 2022.12.09
class Solution {
public:
    string s;
    int m;
    vector<vector<int>> dp;
    int f(int i, int cnt, bool is_limit) {
        if(i == m) {
            return cnt;
        }
        if(!is_limit && dp[i][cnt] >= 0) {
            return dp[i][cnt];
        }
        int res = 0;
        for(int d = 0, up = is_limit ? s[i] - '0' : 9; d <= up; d++) {
            res += f(i + 1, cnt + (d == 1), is_limit && d == up);
        }
        if(!is_limit) {
            dp[i][cnt] = res;
        }
        return res;
    }
    int countDigitOne(int n) {
        s = to_string(n);
        m = s.size();
        dp.resize(m, vector<int>(m, -1));
        return f(0, 0, true);
    }
};

// function variable
// function<int(int, int, bool)> f = [&](int i, int cnt1, bool is_limit) -> int {
//             if (i == m) return cnt1;
//             if (!is_limit && dp[i][cnt1] >= 0) return dp[i][cnt1];
//             int res = 0;
//             for (int d = 0, up = is_limit ? s[i] - '0' : 9; d <= up; ++d) // 枚举要填入的数字 d
//                 res += f(i + 1, cnt1 + (d == 1), is_limit && d == up);
//             if (!is_limit) dp[i][cnt1] = res;
//             return res;
//         };