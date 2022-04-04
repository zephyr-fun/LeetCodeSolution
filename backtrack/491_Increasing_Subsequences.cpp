// 2022.04.03
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex){
        if(path.size() > 1){
            res.push_back(path);
        }
        unordered_set<int> uset;
        for(int i = startIndex; i < nums.size(); i++){
            if ((!path.empty() && path.back() > nums[i]) || uset.find(nums[i]) != uset.end()){
                continue;
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};

// optim space usage
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex){
        if(path.size() > 1){
            res.push_back(path);
        }
        int uset[201] = {0};
        for(int i = startIndex; i < nums.size(); i++){
            if((!path.empty() && nums[i] < path.back()) || uset[nums[i] + 100] != 0){
                continue;
            }
            uset[nums[i] + 100] = 1;
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};

// 2022.04.04
// can't sort in this task
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex){
        if(path.size() > 1){
            res.push_back(path);
        }
        // -100 <= nums[i] <= 100, 201 in total
        int uset[201] = {0};
        for(int i = startIndex; i < nums.size(); i++){
            if(!path.empty() && nums[i] < path.back() || uset[nums[i] + 100] != 0){
                continue;
            }
            uset[nums[i] + 100] = 1;
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            // no need to set uset[nums[i] + 100] = 0, cause uset record single layer, like row
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};