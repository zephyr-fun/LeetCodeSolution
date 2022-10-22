// 2022.10.22
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3, 0));
        for(int i = 0; i < n; i++) {
            jobs[i][0] = endTime[i];
            jobs[i][1] = startTime[i];
            jobs[i][2] = profit[i];
        }
        sort(jobs.begin(), jobs.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        vector<int> dp(n + 1, 0);
        for(int i = 0; i < n; i++) {
            int l = 0;
            int r = i - 1;
            int pos = -1;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(jobs[mid][0] <= jobs[i][1]) {
                    pos = mid;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            dp[i + 1] = max(dp[i], dp[pos + 1] + jobs[i][2]);
        }
        return dp[n];
    }
};