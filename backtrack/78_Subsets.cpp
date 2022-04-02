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