// 2022.10.09
class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int prev = 0;
        int res = 0;
        int maxVal = 0;
        for(auto log : logs) {
            int len = log[1] - prev;
            if(len > maxVal || (len == maxVal && log[0] < res)) {
                maxVal = len;
                res = log[0];
            }
            prev = log[1];
        }
        return res;
    }
};

// 2023.05.05
// 2432_The_Employee_That_Worked_on_the_Longest_Task
class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int m = logs.size();
        int res = logs[0][0];
        int length = logs[0][1];
        for(int i = 1; i < m; i++) {
            if(logs[i][1] - logs[i - 1][1] > length) {
                res = logs[i][0];
                length = logs[i][1] - logs[i - 1][1];
            }
            else if(logs[i][1] - logs[i - 1][1] == length) {
                res = min(res, logs[i][0]);
            }
        }
        return res;
    }
};