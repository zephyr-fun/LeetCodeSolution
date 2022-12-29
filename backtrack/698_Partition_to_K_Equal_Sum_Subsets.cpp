// 2022.09.20
class Solution {
public:
    int target;
    vector<int> nums;
    vector<bool> vis;
    bool dfs(int start, int cnt, int k) {
        if(k == 0) {
            return true;
        }
        if(cnt == target) {
            return dfs(0, 0, k - 1);
        }
        for(int i = start; i < nums.size(); i++) {
            if(vis[i]) {
                continue;
            }
            if(cnt + nums[i] <= target) {
                vis[i] = true;
                if(dfs(i + 1, cnt + nums[i], k)) {
                    return true;
                }
                vis[i] = false;
            }
            while(i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                i++;
            }
            if(!cnt || cnt + nums[i] == target) {
                return false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums_, int k) {
        nums = nums_;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k) {
            return false;
        }
        vis.resize(nums.size());
        target = sum / k;
        return dfs(0, 0, k);
    }
};

// 2022.12.08
class Solution {
public:
    int target;
    vector<int> nums;
    vector<bool> vis;
    bool dfs(int start, int cnt, int k) {
        if(k == 0) {
            return true;
        }
        if(cnt == target) {
            return dfs(0, 0, k - 1);
        }
        for(int i = start; i < nums.size(); i++) {
            if(vis[i]) {
                continue;
            }
            if(cnt + nums[i] <= target) {
                vis[i] = true;
                if(dfs(i + 1, cnt + nums[i], k)) {
                    return true;
                }
                vis[i] = false;
            }
            while(i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                i++;
            }
            // if(!cnt || cnt + nums[i] == target) { // first or last, why?
                return false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums_, int k) {
        nums = nums_;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k) {
            return false;
        }
        vis.resize(nums.size());
        target = sum / k;
        return dfs(0, 0, k);
    }
};