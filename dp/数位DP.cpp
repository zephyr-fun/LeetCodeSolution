// 2023.03.20
// 通用数位DP模板
// 将 n 转换为字符串 s ，定义 f(i, mask, is_limit, is_num) 表示构造从左往右第 i 位及其之后数位的合法方案数，
// 其余参数的含义为：
// mask 表示前面选过的数字集合，换句话说，第 i 位要选的数字不能在 mask 中
// is_limit 表示表示当前是否受到了 n 的约束。若为真，则第 i 位填入的数字至多为 s[i] ，否则可以是 9 。
// 如果在受到约束的情况下填了 s[i] ，那么后续填入的数字仍会受到 n 的约束。
// is_num 表示 i 前面的数位是否填了数字。
// 若为假，则当前位可以跳过（不填数字，即位数比给定数少），或者要填入的数字至少为 1
// 若为真，则必须填数字，且要填入的数字可以从 0 开始。
// C++ 只需要记忆化 (i,mask) 这个状态，因为：
// 对于一个固定的 (i,mask)，这个状态受到 isLimit 或 isNum 的约束在整个递归过程中至多会出现一次，没必要记忆化。
// 另外，如果只记忆化 (i,mask)，dp 数组的含义就变成在不受到约束时的合法方案数，所以要在 !isLimit && isNum 成立时才去记忆化。

// endlesscheng version
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        int m = s.size();
        int dp[m][1 << 10]; // 只记忆 (1, mask)
        memset(dp, -1, sizeof(dp)); // -1 代表未更新记录
        // i, mask, is_limit, is_num
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