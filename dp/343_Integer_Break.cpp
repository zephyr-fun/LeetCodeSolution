// 2022.04.09
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for(int i = 3; i <= n; i++){
            for(int j = 1; j < i - 1; j++){
                dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
            }
        }
        return dp[n];
    }
};

// class Solution {
// public:
//     int integerBreak(int n) {
//         int base = 0;
//         for(int i = 2; i < n; i++){
//             if(n >= i *i){
//                 base = i;
//             }
//         }
//         int res = n - i * i;
//         return pow(i, i - res) * pow(i + 1, res);
//     }
// };