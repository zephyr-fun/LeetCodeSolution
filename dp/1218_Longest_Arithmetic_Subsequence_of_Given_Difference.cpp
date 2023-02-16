// 2022.05.05
// with map
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int size = arr.size();
        unordered_map<int, int> map;
        // dp[i] refers to with selecting arr[i], the maximum length of sub sequence
        vector<int> dp(size, 1); // if arr[i] is the start of a sequence
        int res = 0;
        for(int i = 0; i < size; i++) {
            if(map.find(arr[i] - difference) != map.end()) {
                dp[i] = max(dp[i], dp[map[arr[i] - difference]] + 1);
            }
            map[arr[i]] = i;
            res = max(res, dp[i]);
        }
        return res;
    }
};

// use array to replace map
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int size = arr.size();
        int map[40009];
        memset(map, -1, sizeof(map)); // key point
        int M = 40009 / 2;
        // dp[i] refers to with selecting arr[i], the maximum length of sub sequence
        vector<int> dp(size, 1); // if arr[i] is the start of a sequence
        int res = 0;
        for(int i = 0; i < size; i++) {
            if(map[arr[i] - difference + M] != -1) {
                dp[i] = max(dp[i], dp[map[arr[i] - difference + M]] + 1);
            }
            map[arr[i] + M] = i;
            res = max(res, dp[i]);
        }
        return res;
    }
};

// original
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int size = arr.size();
        int map[40009];
        memset(map, -1, sizeof(map)); // key point
        int M = 40009 / 2;
        // dp[i][j] refers to with not selecting or selecting arr[i], the maximum length of sub sequence, j = {0, 1}, 0 refers to not select, 1 refers to select
        vector<vector<int>> dp(size, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = 1;
        map[arr[0] + M] = 0;
        for(int i = 1; i < size; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = 1;
            if(map[arr[i] - difference + M] != -1) {
                dp[i][1] = max(dp[i][1], dp[map[arr[i] - difference + M]][1] + 1);
            }
            map[arr[i] + M] = i;
        }
        return max(dp[size - 1][0], dp[size - 1][1]);
    }
};

// 2022.05.10
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int size = arr.size();
        int map[40009];
        memset(map, -1, sizeof(map));
        int M = 40009 / 2;
        vector<int> dp(size, 1);
        int res = 0;
        for(int i = 0; i < size; i++) {
            if(map[arr[i] - difference + M] != -1) {
                dp[i] = dp[map[arr[i] - difference + M]] + 1; // no need for max
            }
            map[arr[i] + M] = i;
            res = max(res, dp[i]);
        }
        return res;
    }
};

// 2022.05.11
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // dp[i] refers to the maximum length with must select arr[i]
        vector<int> dp(arr.size(), 1);
        // how to calc range of map? -1e4 <= arr[i], difference <= 1e4, 4*1e4
        int map[40009];
        memset(map, -1, sizeof(map));
        int M = 40009 / 2;
        int res = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(map[arr[i] - difference + M] != -1) {
                dp[i] = dp[map[arr[i] - difference + M]] + 1;
            }
            map[arr[i] + M] = i;
            res = max(res, dp[i]);
        }
        return res;
    }
};

// 2023.02.16
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        int dp[n][2];
        memset(dp, 0, sizeof(dp));
        dp[0][1] = 1;
        int offset = 2e4;
        int tot = 4e4 + 7;
        int map[tot];
        memset(map, -1, sizeof(map));
        map[arr[0] + offset] = 0;
        for(int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = 1;
            int prev = arr[i] - difference + offset;
            if(map[prev] != -1) {
                dp[i][1] = max(dp[map[prev]][1] + 1, dp[i][1]);
            }
            else {
                dp[i][1] = 1;
            }
            map[arr[i] + offset] = i;
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};

// 2023.02.16
// use map to replace dp[][]
// map[a, b] -> current value, with length
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        int tot = 4e4 + 7;
        int offset = 2e4;
        int res = 1;
        int map[tot]; // val, length
        memset(map, -1, sizeof(map));
        for(int i = 0; i < n; i++) {
            map[arr[i] + offset] = max(1, map[arr[i] + offset - difference] + 1);
            res = max(res, map[arr[i] + offset]);
        }
        return res;
    }
};