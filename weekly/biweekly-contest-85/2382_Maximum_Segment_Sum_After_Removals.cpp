// 2022.08.29
class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        vector<int> parent(n + 1, 0);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        function<int(int)> find = [&] (int x) -> int {
            if(x != parent[x]) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };
        vector<long long> sum(n + 1, 0);
        vector<long long> res(n);
        for(int i = n - 1; i > 0; i--) {
            int x = removeQueries[i];
            int to = find(x + 1);
            parent[x] = to;
            sum[to] += sum[x] + nums[x];
            res[i - 1] = max(res[i], sum[to]);
        }
        return res;
    }
};