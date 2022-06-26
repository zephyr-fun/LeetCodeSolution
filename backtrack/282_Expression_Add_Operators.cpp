// 2022.06.26
class Solution {
public:
    vector<string> res;
    string s;
    int n, t;
    vector<string> addOperators(string num, int target) {
        s = num;
        n = s.size();
        t = target;
        dfs(0, 0, 0, "");
        return res;
    }
    void dfs(int u, long long prev, long long cur, string path) {
        if(u == n) {
            if(cur == t) {
                res.emplace_back(path);
            }
            return ;
        }
        for(int i = u; i < n; i++) {
            if(i != u && s[u] == '0') { // 012 dont work
                break;
            }
            long long next = stoll(s.substr(u, i - u + 1)); // both works
            if(u == 0) {
                dfs(i + 1, next, next, "" + to_string(next));
            }
            else {
                dfs(i + 1, next, cur + next, path + "+" + to_string(next));
                dfs(i + 1, -next, cur - next, path + "-" + to_string(next));
                long long x = prev * next;
                dfs(i + 1, x, cur - prev + x, path + "*" + to_string(next));
            }
        }
    }
};

// dfs
class Solution {
public:
    vector<string> res;
    string s;
    int n;
    int t;
    void dfs(int u, long long prev, long long cur, string path) {
        if(u == n) {
            if(cur == t) {
                res.emplace_back(path);
            }
            return ;
        }
        for(int i = u; i < n; i++) {
            if(i != u && s[u] == '0') { // 012 dont work
                break;
            }
            long long next = stoll(s.substr(u, i - u + 1));
            if(u == 0) {
                dfs(i + 1, next, next, "" + to_string(next));
            }
            else {
                dfs(i + 1, next, cur + next, path + "+" + to_string(next));
                dfs(i + 1, -next, cur - next, path + "-" + to_string(next));
                long long x = cur - prev;
                dfs(i + 1, prev * next, x + prev * next, path + "*" + to_string(next));
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        s = num;
        n = num.size();
        t = target;
        dfs(0, 0, 0, "");
        return res;
    }
};