// 2022.11.14
// 2022.11.14
class Solution {
public:
    vector<int> nums;
    unordered_multiset<int> set;

    void dfs1(int u, int n, int sum) {
        if(u == n) {
            set.insert(sum);
        }
        else {
            dfs1(u + 1, n, sum);
            dfs1(u + 1, n, sum + nums[u]);
        }
    }

    bool dfs2(int u, int n, int sum, int cnt) {
        if(u == n) {
            if(cnt && cnt < n && set.count(-sum)) {
                return true;
            }
            return false;
        }
        else {
            if(dfs2(u + 1, n, sum, cnt)) {
                return true;
            }
            if(dfs2(u + 1, n, sum + nums[u], cnt + 1)) {
                return true;
            }
            return false;
        }
    }

    bool splitArraySameAverage(vector<int>& _nums) {
        nums = _nums;
        int n = nums.size();
        if(n == 1) {
            return false;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for(auto& x: nums) {
            x = x * n - sum;
        }
        int m = n / 2;
        dfs1(m, n, 0);
        int s1 = 0;
        int s2 = accumulate(nums.begin() + m, nums.begin() + n, 0);
        set.erase(set.find(s1));
        if(set.count(0)) {
            return true;
        }
        set.insert(s1);
        set.erase(set.find(s2));
        if(set.count(-accumulate(nums.begin(), nums.begin() + m, 0))) {
            return true;
        }
        return dfs2(0, m, 0, 0);
    }
};