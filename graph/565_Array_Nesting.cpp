// 2022.07.17
// same idea, diff result, TLE
class Solution {
public:
    int res = 0;
    vector<int> nums;
    unordered_set<int> set;
    void dfs(unordered_set<int>& set, int cur, int cnt) {
        if(set.count(nums[cur])) {
            return ;
        }
        res = max(res, cnt);
        set.insert(nums[cur]);
        dfs(set, nums[cur], cnt + 1);
        set.erase(nums[cur]);
    }
    int arrayNesting(vector<int>& nums_) {
        nums = nums_;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            dfs(set, i, 0);
        }
        return res + 1;
    }
};

// optim above
class Solution {
public:
    int res = 0;
    vector<int> nums;
    void dfs(int cur, int cnt) {
        if(nums[cur] == -1) {
            res = max(res, cnt);
            return ;
        }
        int temp = nums[cur];
        nums[cur] = -1;
        dfs(temp, cnt + 1);
    }
    int arrayNesting(vector<int>& nums_) {
        nums = nums_;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            dfs(i, 0);
        }
        return res;
    }
};

// optim, mark point
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            int cur = i;
            int cnt = 0;
            while(nums[cur] != -1) {
                cnt++;
                int temp = cur;
                cur = nums[cur];
                nums[temp] = -1;
            }
            res = max(res, cnt);
        }
        return res;
    }
};