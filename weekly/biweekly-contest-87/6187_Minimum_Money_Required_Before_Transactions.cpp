// 2022.09.17
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        sort(transactions.begin(), transactions.end(), [](vector<int>& a, vector<int>& b) {
            long long min1 = (long long)min(-a[0], -a[0] + a[1] - b[0]);
            long long min2 = (long long)min(-b[0], -b[0] + b[1] - a[0]);
            if(min1 == min2) {
                return a[0] > b[0];
            }
            return min1 < min2;
        });
        long long res = 0;
        long long cur = 0;
        for(auto& ts : transactions) {
            cur -= ts[0];
            res = min(res, cur);
            cur += ts[1];
        }
        return -res;
    }
};