class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1, 0);
        return res;
    }
    void backtracking(int k, int n, int startIndex, int sum){
        if(sum > n){ // cut
            return ;
        }
        if(path.size() == k){
            if(sum == n){
                res.push_back(path);
            }
            return ;
        }
        for(int i = startIndex; i <= 9 - (k - path.size()) + 1; i++){ // cut
            sum += i;
            path.push_back(i);
            backtracking(k, n, i + 1, sum);
            path.pop_back();
            sum -= i;
        }
    }
};