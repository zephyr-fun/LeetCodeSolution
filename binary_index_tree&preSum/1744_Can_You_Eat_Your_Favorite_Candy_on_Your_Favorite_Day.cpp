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

// 2022.06.16
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        int m = queries.size();
        vector<long> sum(n + 1, 0); // note type long
        for(int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + candiesCount[i - 1];
        }
        vector<bool> res(m, false);
        for(int i = 0; i < m; i++) {
            int type = queries[i][0];
            int day = queries[i][1] + 1;
            int cap = queries[i][2];
            long early = sum[type] / cap + 1; // note type long
            long later = sum[type + 1]; // note type long
            if(day >= early && day <= later) {
                res[i] = true;
            }
        }
        return res;
    }
};

// 2023.03.06
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        long cnt[n + 1];
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++) {
            cnt[i + 1] = cnt[i] + candiesCount[i];
        }
        int m = queries.size();
        vector<bool> res(m, false);
        for(int i = 0; i < m; i++) {
            int type = queries[i][0];
            int day = queries[i][1] + 1;
            int cap = queries[i][2];
            long early = cnt[type] / cap + 1;
            long later = cnt[type + 1];
            if(day >= early && day <= later) {
                res[i] = true;
            }
        }
        return res;
    }
};