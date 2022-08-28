// 2022.08.28
// plain O(n^2) dp, TLE
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            dp[i] = dp[i - 1];
            for(int j = i - 1; j >= 0; j--) {
                if(intervals[i][0] >= intervals[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return n - dp[n - 1];
    }
};

// dp + binary search
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            dp[i] = dp[i - 1];
            int left = 0;
            int right = i - 1;
            int pos = -1;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(intervals[mid][1] <= intervals[i][0]) {
                    pos = mid;
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            if(pos != -1) {
                dp[i] = max(dp[i], dp[pos] + 1);
            }
        }
        return n - dp[n - 1];
    }
};

// greedy
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 1;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int end = intervals[0][1];
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] >= end) {
                count++;
                end = intervals[i][1];
            }
        }
        return n - count;
    }
};