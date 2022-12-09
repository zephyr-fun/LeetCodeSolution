// 灵神模板
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        auto s = to_string(n);
        int m = s.length();
        int dp[m];
        memset(dp, -1, sizeof(dp)); // dp[i] = -1 表示 i 这个状态还没被计算出来
        function<int(int, bool, bool)> f = [&](int i, bool is_limit, bool is_num) -> int {
            if(i == m) {
                return is_num; // 如果填了数字，则为 1 种合法方案
            }
            if(!is_limit && is_num && dp[i] >= 0) {
                return dp[i]; // 在不受到任何约束的情况下，返回记录的结果，避免重复运算
            }
            int res = 0;
            if(!is_num) {// 前面不填数字，那么可以跳过当前数位，也不填数字
                // is_limit 改为 false，因为没有填数字，位数都比 n 要短，自然不会受到 n 的约束
                // is_num 仍然为 false，因为没有填任何数字
                res = f(i + 1, false, false);
            }
            char up = is_limit ? s[i] : '9'; // 根据是否受到约束，决定可以填的数字的上限
            // 注意：对于一般的题目而言，如果这里 is_num 为 false，则必须从 1 开始枚举，由于本题 digits 没有 0，所以无需处理这种情况
            for(auto &d : digits) { // 枚举要填入的数字 d
                if(d[0] > up) {
                    break; // d 超过上限，由于 digits 是有序的，后面的 d 都会超过上限，故退出循环
                }
                // is_limit：如果当前受到 n 的约束，且填的数字等于上限，那么后面仍然会受到 n 的约束
                // is_num 为 true，因为填了数字
                res += f(i + 1, is_limit && d[0] == up, true);
            }
            if(!is_limit && is_num) {
                dp[i] = res; // 在不受到任何约束的情况下，记录结果
            }
            return res;
        };
        return f(0, true, false);
    }
};