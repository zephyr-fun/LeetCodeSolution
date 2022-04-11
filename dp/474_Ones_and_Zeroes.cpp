// 2022.04.11
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(string str : strs){
            int numOne = 0;
            int numZero = 0;
            for(char c : str){
                if(c == '0'){
                    numZero++;
                }
                else{
                    numOne++;
                }
            }
            for(int i = m; i >= numZero; i--){
                for(int j = n; j >= numOne; j--){
                    dp[i][j] = max(dp[i][j], dp[i - numZero][j - numOne] + 1);
                }
            }
        }
        return dp[m][n];
    }
};