// 2022.04.01
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;
    }
    void backtracking(int n, int k, int startIndex){
        if(path.size() == k){
            res.push_back(path);
            return ;
        }
        for(int i = startIndex; i <= n - (k - path.size()) + 1; i++){// optim n - (k - path.size()) + 1 for n
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
};

// 2022.04.04
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int n, int k, int startIndex){
        if(path.size() == k){
            res.push_back(path);
            return ;
        }
        for(int i = startIndex; i <= n - (k - path.size()) + 1; i++){
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;
    }
};