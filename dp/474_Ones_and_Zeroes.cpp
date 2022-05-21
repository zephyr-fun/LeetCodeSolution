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

// 2022.05.08
// 2-dim 0-1 bag
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(auto str : strs) {
            int zeroNum = 0;
            int oneNum = 0;
            for(int i = 0; i < str.size(); i++) {
                if(str[i] == '0') {
                    zeroNum++;
                }
                else {
                    oneNum++;
                }
            }
            for(int i = m; i >= zeroNum; i--) {
                for(int j = n; j >= oneNum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};


// 2022.05.21
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // dp[i][j][k] refers to considering first i strings, at most j 0, k 1, max set number
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for(int i = 1; i <= strs.size(); i++) {
            int oneNum = 0;
            int zeroNum = 0;
            for(int count = 0; count < strs[i - 1].size(); count++) {
                if(strs[i - 1][count] == '0') {
                    zeroNum++;
                }
                else {
                    oneNum++;
                }
            }
            for(int j = 0; j <= m; j++) {
                for(int k = 0; k <= n; k++) {
                    if(j >= zeroNum && k >= oneNum) {
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - zeroNum][k - oneNum] + 1);
                    }
                    else {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }
        return dp[strs.size()][m][n];
    }
};

// optim i dim
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // dp[j][k] refers to considring i first strings, at most j 0, k 1, maximum number
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= strs.size(); i++) {
            int oneNum = 0;
            int zeroNum = 0;
            for(int count = 0; count < strs[i - 1].size(); count++) {
                if(strs[i - 1][count] == '0') {
                    zeroNum++;
                }
                else {
                    oneNum++;
                }
            }
            for(int j = m; j >= zeroNum; j--) {
                for(int k = n; k >= oneNum; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - zeroNum][k - oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};