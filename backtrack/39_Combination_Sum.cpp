// 2022.04.02
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex){
        if(sum > target){
            return ;
        }
        if(sum == target){
            res.push_back(path);
            return ;
        }
        for(int i = startIndex; i < candidates.size(); i++){
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size() == 0){
            return res;
        }
        backtracking(candidates, target, 0, 0);
        return res;
    }
};

// optim
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex){
        // judged from last leyer
        // if(sum > target){
        //     return ;
        // }
        if(sum == target){
            res.push_back(path);
            return ;
        }
        for(int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++){ //&& sum + candidates[i] <= target
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size() == 0){
            return res;
        }
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return res;
    }
};