// 2022.07.09
// without cur brunch
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> map;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            map[arr[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(arr[i] - arr[j] >= arr[j]) {
                    continue;
                }
                int t = -1;
                if(map.count(arr[i] - arr[j])) {
                    t = map[arr[i] - arr[j]];
                }
                if(t == -1) {
                    continue;
                }
                dp[i][j] = max(dp[j][t] + 1, 3);
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};

// optim
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> map;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            map[arr[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i - 1; j >= 0 && j + 2 >res; j--) {
                if(arr[i] - arr[j] >= arr[j]) {
                    break;
                }
                int t = -1;
                if(map.count(arr[i] - arr[j])) {
                    t = map[arr[i] - arr[j]];
                }
                if(t == -1) {
                    continue;
                }
                dp[i][j] = max(dp[j][t] + 1, 3);
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};

// repeat
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++) {
            map[arr[i]] = i;
        }
        int res = 0;
        // dp[i][j] refers to max length of t, j, i
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = i - 1; j >= 0 && j + 2 > res; j--) {
                if(arr[i] - arr[j] >= arr[j]) {
                    break;
                }
                int t = -1;
                if(map.count(arr[i] - arr[j])) {
                    t = map[arr[i] - arr[j]];
                }
                if(t == -1) {
                    continue;
                }
                dp[i][j] = max(3, dp[j][t] + 1);
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};