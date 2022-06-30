// 2022.06.30
// plain dfs
class Solution {
public:
    vector<string> res;
    int n;
    void dfs(string path, int cnt, int l, int r) {
        if(path.size() == 2 * n) {
            if(cnt == 0) {
                res.emplace_back(path);
            }
            return ;
        }
        if(cnt < 0 || l < 0 || r < 0) {
            return ;
        }
        dfs(path + '(', cnt + 1, l - 1, r);
        dfs(path + ')', cnt - 1, l, r - 1);
    }
    vector<string> generateParenthesis(int n_) {
        n = n_;
        dfs("", 0, n, n);
        return res;
    }
};

// dp
