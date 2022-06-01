// 2022.06.01
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = candiesCount.size();
        vector<bool> res(n, false);
        vector<long> sum(m + 1, 0);
        for(int i = 1; i <= m; i++) {
            sum[i] = sum[i - 1] + candiesCount[i - 1];
        }
        for(int i = 0; i < n; i++) {
            int type = queries[i][0];
            int day = queries[i][1] + 1; // we count from day 1
            int cap = queries[i][2];
            long early = sum[type] / cap + 1;
            long later = sum[type + 1];
            res[i] = (early <= day && day <= later);
        }
        return res;
    }
};