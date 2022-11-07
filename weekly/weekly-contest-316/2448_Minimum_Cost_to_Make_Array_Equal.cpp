// 2022.11.07 update
// 带权中位数
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        long long tot = 0;
        vector<vector<int>> nc(n, vector<int>(2));
        for(int i = 0; i < n; i++) {
            nc[i][0] = nums[i];
            nc[i][1] = cost[i];
            tot += cost[i];
        }
        sort(nc.begin(), nc.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        long long cur = 0;
        int chosen;
        for(int i = 0; i < n; i++) {
            cur += nc[i][1];
            if(cur >= tot / 2) {
                chosen = nc[i][0];
                break;
            }
        }
        long long res = 0;
        for(int i = 0; i < n; i++) {
            res += (long long)abs(nums[i] - chosen) * (long long)cost[i];
        }
        return res;
    }
};