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

// 2022.04.04
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int k, int n, int startIndex, int sum){
        if(sum > n){
            return ;
        }
        if(k == path.size()){
            if(sum == n){
                res.push_back(path);
            }
            return ;
        }
        for(int i = startIndex; i <= 9 - (k - path.size()) + 1; i++){ // notice '<='
            sum += i;
            path.push_back(i);
            backtracking(k, n, i + 1, sum);
            sum -= i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1, 0);
        return res;
    }
};

// 2022.12.19
class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    int k;
    int n;
    void dfs(int num, int idx, int left) {
        if(left == 0 && num == k) {
            res.emplace_back(cur);
            return ;
        }
        if(idx > left || idx > 9 || num > k) {
            return ;
        }
        for(int i = idx; i <= 9; i++) {
            cur.emplace_back(i);
            dfs(num + 1, i + 1, left - i);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k_, int n_) {
        k = k_;
        n = n_;
        dfs(0, 1, n);
        return res;
    }
};