// 2022.05.02 retroactive 2022.05.01
// variant of last one
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int len = arr.size();
        int up = 1;
        int down = 1;
        int ans = 1;
        for(int i = 1; i < len; i++) {
            if(arr[i] > arr[i - 1]) {
                up = down + 1;
                down = 1;
            }
            else if(arr[i] < arr[i - 1]) {
                down = up + 1;
                up = 1;
            }
            else {
                up = 1;
                down = 1;
            }
            ans = max(ans, max(up, down));
        }
        return ans;
    }
};

// plain dp with intuition
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int size = arr.size();
        int res = 1;
        vector<vector<int>> dp(size, vector<int>(2, 0));
        dp[0][0] = 1;
        dp[0][1] = 1;
        for(int i = 1; i < size; i++) {
            f[i][0] = 1;
            f[i][1] = 1;
            if(arr[i] > arr[i - 1]) {
                f[i][0] = f[i - 1][1] + 1;
            }
            else if(arr[i] < arr[i - 1]) {
                f[i][0] = f[i - 1][0] + 1;
            }
            res = max(ans, max(f[i][0], f[i][1]));
        }
        return res;
    }
};

// roll
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int size = arr.size();
        int res  =1;
        vector<vector<int>> dp(2, vector<int>(2, 0));
        dp[0][0] = 1;
        dp[0][1] = 1;
        for(int i = 1; i < size; i++) {
            dp[i % 2][0] = 1;
            dp[i % 2][1] = 1;
            if(arr[i] > arr[i - 1]) {
                dp[i % 2][0] = dp[(i - 1) % 2][1] + 1;
            }
            else if(arr[i] < arr[i - 1]) {
                dp[i % 2][1] = dp[(i - 1) % 2][0] + 1;
            }
            res = max(res, max(dp[i % 2][0], dp[i % 2][1]));
        }
        return res;
    }
};

// remove first dim
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int size = arr.size();
        int res  =1;
        vector<int> dp(2, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 1; i < size; i++) {
            int a = dp[0];
            int b = dp[1];
            dp[0] = arr[i] > arr[i - 1] ? b + 1 : 1;
            dp[1] = arr[i] < arr[i - 1] ? a + 1 : 1;
            res = max(res, max(dp[0], dp[1]));
        }
        return res;
    }
};

// 2022.05.22
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int size = arr.size();
        // dp[i][j] refers to with selecting first i nums, j{0, 1} max len
        vector<vector<int>> dp(size + 1, vector<int>(2, 0));
        dp[1][0] = 1; // up
        dp[1][1] = 1; // down
        int res = 1;
        for(int i = 1; i < size; i++) {
            dp[i + 1][0] = 1;
            dp[i + 1][1] = 1;
            if(arr[i] > arr[i - 1]) {
                dp[i + 1][0] = dp[i][1] + 1;
            }
            else if(arr[i] < arr[i - 1]) {
                dp[i + 1][1] = dp[i][0] + 1;
            }
            res = max(res, max(dp[i + 1][0], dp[i + 1][1]));
        }
        return res;
    }
};

// optim i dim
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int size = arr.size();
        // dp[i][j] refers to with selecting first i nums, j{0, 1} len
        int dp[2];
        dp[0] = 1;
        dp[1] = 1;
        int res = 1;
        for(int i = 1; i < size; i++) {
            int a = dp[0];
            int b = dp[1];
            if(arr[i] > arr[i - 1]) {
                dp[0] = b + 1;
                dp[1] = 1;
            }
            else if(arr[i] < arr[i - 1]){
                dp[0] = 1;
                dp[1] = a + 1;
            }
            else {
                dp[0] = 1;
                dp[1] = 1;
            }
            res = max(res, max(dp[0], dp[1]));
        }
        return res;
    }
};

// 2023.06.02
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int dp[n][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        dp[0][1] = 1;
        int res = 1;
        for(int i = 1; i < n; i++) {
            dp[i][0] = arr[i] > arr[i - 1] ? dp[i - 1][1] + 1 : 1;
            dp[i][1] = arr[i] < arr[i - 1] ? dp[i - 1][0] + 1 : 1;
            res = max(res, max(dp[i][0], dp[i][1]));
        }
        return res;
    }
};