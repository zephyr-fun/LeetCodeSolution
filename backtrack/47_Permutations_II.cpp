// 2022.04.03
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used){
        if(path.size() == nums.size()){
            res.push_back(path);
            return ;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i] == true || i > 0 && used[i - 1] == false && nums[i] == nums[i - 1]){
                continue;
            }
            else{
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                used[i] = false;
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }
};