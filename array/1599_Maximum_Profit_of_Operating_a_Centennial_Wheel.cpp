// 2023.03.05
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int res = -1;
        int mx = 0;
        int t = 0;
        int wait = 0;
        int i = 0;
        while(wait || i < customers.size()) {
            wait += i < customers.size() ? customers[i] : 0;
            int up = min(4, wait);
            wait -= up;
            i++;
            t += up * boardingCost - runningCost;
            if(t > mx) {
                t = mx;
                res = i;
            }
        }
        return res;
    }
};