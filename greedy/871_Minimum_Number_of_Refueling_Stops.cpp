// 2022.07.02
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pque;
        int n = stations.size();
        int idx = 0;
        int remain = startFuel;
        int loc = 0;
        int res = 0;
        while(loc < target) {
            if(remain == 0) {
                if(!pque.empty() && ++res >= 0) {
                    remain += pque.top();
                    pque.pop();
                }
                else {
                    return -1;
                }
            }
            loc += remain;
            remain = 0;
            while(idx < n && stations[idx][0] <= loc) {
                pque.push(stations[idx][1]);
                idx++;
            }
        }
        return res;
    }
};