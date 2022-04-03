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