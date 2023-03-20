// 2022.05.21
class Solution {
public:
    int numDupDigitsAtMostN(int _n) {
        // f[i][j] = i * (i + 1) * ...... * (j - 1) * j
        int f[10][10];
        for(int i = 1; i < 10; i++) {
            for(int j = 1; j < 10; j++) {
                int cur = 1;
                for(int k = i; k <= j; k++) {
                    cur *= k;
                }
                f[i][j] = cur;
            }
        }
        int x = _n;
        vector<int> nums;
        while(x != 0) {
            nums.push_back(x % 10);
            x /= 10;
        }
        int n = nums.size();
        if(n <= 1) {
            return 0;
        }
        // same len
        int res = 0;
        for(int i = n - 1, p = 1, s = 0; i >= 0; i--, p++) {
            int cur = nums[i];
            int cnt = 0;
            // calc valid num
            for(int j = cur - 1; j >= 0; j--) {
                if(i == n - 1 && j == 0) {
                    continue;
                }
                if(((s >> j) & 1) == 0) {
                    cnt++;
                }
            }
            int a = 10 - p;
            int b = a - (n - p) + 1;
            res += b <= a ? cnt * f[b][a] : cnt;
            if(((s >> cur) & 1) == 1) {
                break;
            }
            s |= (1 << cur);
            if(i == 0) {
                res++;
            }
        }
        // less len
        res += 10;
        for(int i = 2, last = 9; i < n; i++) {
            int cur = last * (10 - i + 1);
            res += cur;
            last = cur;
        }
        return _n - res + 1;
    }
};

// 2023.03.20
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        int m = s.size();
        int dp[m][1 << 10];
        memset(dp, -1, sizeof(dp));
        function<int(int, int, bool, bool)> dfs = [&] (int i, int mask, bool is_limit, bool is_num) {
            if(i == m) {
                return (int) is_num;
            }
            if(!is_limit && is_num && dp[i][mask] >= 0) { // dp[i][mask] != -1
                return dp[i][mask];
            }
            int res = 0;
            if(!is_num) {
                res = dfs(i + 1, mask, false, false);
            }
            int up = is_limit ? s[i] - '0' : 9;
            for(int d = 1 - (int) is_num; d <= up; d++) {
                if((mask >> d & 1) == 0) {
                    res += dfs(i + 1, mask | (1 << d), is_limit && d == up, true);
                }
            }
            // record the state
            if(!is_limit && is_num) {
                dp[i][mask] = res;
            }
            return res;
        };
        return n - dfs(0, 0, true, false);
    }
};