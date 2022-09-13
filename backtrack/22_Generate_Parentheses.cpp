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

// 2022.09.13
class Solution {
public:
    vector<string> res;
    string path;
    int total;
    int n;
    void dfs(int cur) {
        if(path.size() == total) {
            if(cur == 0) {
                res.emplace_back(path);
            }
            return ;
        }
        if(cur < n) {
            path += '(';
            dfs(cur + 1);
            path.pop_back();
        }
        if(cur >= 1) {
            path += ')';
            dfs(cur - 1);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n_) {
        n = n_;
        total = 2 * n;
        dfs(0);
        return res;
    }
};