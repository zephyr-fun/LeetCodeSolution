// 2022.04.02
class Solution {
public:
    vector<vector<int>> res;
    vector<int> pathnode;
    void backtracking(vector<int>& nums, int startIndex){
        res.push_back(pathnode);
        if(startIndex >= nums.size()){
            return ;
        }
        for(int i = startIndex; i < nums.size(); i++){
            pathnode.push_back(nums[i]);
            backtracking(nums, i + 1);
            pathnode.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};

// 2022.04.04
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex){
        res.push_back(path);
        if(startIndex >= nums.size()){ // avoid infinite recursion
            return ;
        }
        for(int i = startIndex; i < nums.size(); i++){
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};

// 2023.03.13
// bit operation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        for(int mask = 0; mask < (1 << n); mask++) {
            vector<int> temp;
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    temp.emplace_back(nums[i]);
                }
            }
            res.emplace_back(temp);
        }
        return res;
    }
};

// chose or not
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        int n = nums.size();
        function<void(int)> dfs = [&] (int cur) {
            if(cur == n) {
                res.emplace_back(path);
                return ;
            }
            // not chose
            dfs(cur + 1);

            // chose and recover(return to last layer)
            path.emplace_back(nums[cur]);
            dfs(cur + 1);
            path.pop_back();
        };
        dfs(0);
        return res;
    }
};