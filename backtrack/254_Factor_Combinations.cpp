// 2022.09.04
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> getFactors(int n) {
        dfs(2, n);
        return res;
    }
    void dfs(int start, int n) {
        if(n == 1) {
            if(path.size() > 1) {
                res.emplace_back(path);
            }
        }
        for(int i = start; i <= n; i++) {
            if(n % i == 0) {
                path.emplace_back(i);
                dfs(i, n / i);
                path.pop_back();
            }
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int>> res = solution.getFactors(32);
    for(auto re : res) {
        for(auto r : re) {
            cout << r << " ";
        }
        cout << endl;
    }
    return 0;
}