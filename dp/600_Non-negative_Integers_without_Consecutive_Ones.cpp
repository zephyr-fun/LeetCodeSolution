// 2022.05.18
// class Solution {
// public:
//     int findIntegers(int n) {
//         //int是32位，稍微取大一点40
//         int N = 40;
//         //f[i][j]，长度为i，最高位是j时的合法数的数量，
//         //注意这个j不是指合法数的最高位，而是限定一个查询域，域最高位是j，后面几位随意
//         //合法数就是满足题目条件不存在两个连续1的数，注意f还不考虑小于n这个条件，（硬要说的话就是小于二进制j11...1长度为i）
//         int f[N][2];
//         //长度为1的时候，如果j是0，满足条件的就只有0，如果j是1，满足条件的就有0，1
//         f[1][0] = 1, f[1][1] = 2;
//         //模拟一下长度为2的时候，
//         //如果j是0，满足条件的就有00，01，就是上面长度为1，j为1时的数量，
//         //如果j是1，j为0的情况都是满足的，还有就是最高位为1，他的前一位必须为0，那么就是长度为1，j为0的情况
//         for(int i = 2; i < N; i++){
//             f[i][0] = f[i - 1][1];
//             //f[i][1] = f[i][0] + f[i - 1][0];
//             f[i][1] = f[i - 1][0] + f[i - 1][1];
//         }
//         int len = 0;
//         while(n >> len){
//             len ++;
//         }
//         int ans = 0;
//         int cur, pre;
//         while(len){
//             len--;
//             cur = (n >> len) & 1;
//             //如果是1，那么f中长度为len+1最高位是0对应的合法数都可以加进去，而如果是0，因为不能确定是否小于n，还得看下面的迭代
//             if(cur == 1) ans += f[len + 1][0];
//             //如果连续出现两次1，就不满足题目条件了，上一次循环我们已经把最高位（也就是这一次的前一位）为0的情况全加进去了，现在考虑的时候默认前一位为1了
//             if(cur == 1 && pre == 1) break;
//             //如果是最后一位，如果是1，那么上面就加了2，如果是0，因为后面不迭代了，得把对应的f[1][0]加进去，就是1。
//             if(len == 0) ans ++;
//             pre = cur;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int findIntegers(int n) {
        // int 32bit
        int N = 37;
        // dp[i][j] refers to the amount of valid number with highest bit equals to j{0 ,1}, i length
        int dp[N][2];
        dp[1][0] = 1; // 0
        dp[1][1] = 2; // 0, 1
        for(int i = 1; i < N - 1; i++) {
            dp[i + 1][0] = dp[i][1];
            dp[i + 1][1] = dp[i][0] + dp[i][1];
        }
        int len = 0;
        while(n >> len) {
            len++;
        }
        int res = 0;
        int prev = 0;
        while(len) {
            len--;
            int cur = (n >> len) & 1;
            if(cur == 1) {
                res += dp[len + 1][0];
            }
            if(cur == 1 && prev == 1) {
                break;
            }
            prev = cur;
            if(len == 0) {
                res++;
            }
        }
        return res;
    }
};