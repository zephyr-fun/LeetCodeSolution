// 2022.05.09
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int size = events.size();
        vector<vector<int>> dp(size + 1, vector<int>(k + 1, 0));
        for(int i = 1; i <= size; i++) {
            vector<int> ev = events[i - 1];
            int start = ev[0];
            int end = ev[1];
            int value = ev[2];

            int last = 0;
            for(int p = i - 1; p >= 1; p--) {
                vector<int> prev = events[p - 1];
                if(prev[1] < start) {
                    last = p;
                    break;
                }
            }
            for(int j = 1; j <= k; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[last][j - 1] + value);
            }
        }
        return dp[size][k];
    }
};

// binary search
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int size = events.size();
        vector<vector<int>> dp(size + 1, vector<int>(k + 1, 0));
        for(int i = 1; i <= size; i++) {
            vector<int> ev = events[i - 1];
            int start = ev[0];
            int end = ev[1];
            int value = ev[2];

            int left = 1;
            int right = i - 1;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                vector<int> prev = events[mid - 1];
                if(prev[1] >= start) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            int last = right;
            for(int j = 1; j <= k; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[last][j - 1] + value);
            }
        }
        return dp[size][k];
    }
};

// another binary search
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int size = events.size();
        vector<vector<int>> dp(size + 1, vector<int>(k + 1, 0));
        for(int i = 1; i <= size; i++) {
            vector<int> ev = events[i - 1];
            int start = ev[0];
            int end = ev[1];
            int value = ev[2];

            int left = 1;
            int right = i - 1;
            while(left < right) {
                int mid = left + right + 1 >> 1;
                vector<int> prev = events[mid - 1];
                if(prev[1] < start) {
                    left = mid;
                }
                else {
                    right = mid - 1;
                }
            }
            int last = (right > 0 && events[right - 1][1] < start) ? right : 0;
            for(int j = 1; j <= k; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[last][j - 1] + value);
            }
        }
        return dp[size][k];
    }
};