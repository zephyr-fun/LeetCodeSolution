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