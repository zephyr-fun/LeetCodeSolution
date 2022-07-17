// 2022.07.17
class Solution {
public:
    unordered_set<string> wd;
    vector<string> res;
    void dfs(string& s, int cur) {
        if(cur == s.size()) {
            res.emplace_back(s.substr(0, s.size() - 1));
            return ;
        }
        for(int i = cur; i < s.size(); i++) {
            if(wd.count(s.substr(cur, i - cur + 1))) {
                s.insert(s.begin() + i + 1, ' ');
                dfs(s, i + 2);
                s.erase(s.begin() + i + 1);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto w : wordDict) {
            wd.insert(w);
        }
        dfs(s, 0);
        return res;
    }
};