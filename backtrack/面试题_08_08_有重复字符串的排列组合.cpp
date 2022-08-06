// 2022.08.06
class Solution {
public:
    int n;
    vector<bool> vis;
    string s;
    unordered_set<string> res;
    void dfs(string cur) {
        if(cur.size() == n) {
            res.insert(cur);
            return ;
        }
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                vis[i] = true;
                dfs(cur + s[i]);
                vis[i] = false;
            }
        }
    }
    vector<string> permutation(string S) {
        s = S;
        n = s.size();
        vis.resize(n, false);
        dfs("");
        return vector<string>(res.begin(), res.end());
    }
};