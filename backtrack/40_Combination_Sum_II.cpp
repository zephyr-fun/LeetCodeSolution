// 2022.04.02
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used){
        if(sum == target){
            res.push_back(path);
            return ;
        }
        for(int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++){
            if(i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false){
                continue; //deep and wide cut
            }
            // same as above, remove used vector
            // if (i > startIndex && candidates[i] == candidates[i - 1]) {
            //     continue;
            // }
            used[i] = true;
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i + 1, used);
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size() == 0){
            return res;
        }
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);     
        return res;
    }
};

// 2022.04.04
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex){
        if(sum == target){
            res.push_back(path);
            return ;
        }
        for(int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++){
            if(i > startIndex && candidates[i] == candidates[i - 1]){// same layer cut
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i + 1);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size() == 0){
            return res;
        }
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return res;
    }
};