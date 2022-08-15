// 2022.08.14 contest 2022.08.15 update
class Solution {
public:
    string res = "";
    string p;
    unordered_set<char> set;
    void dfs(string s, int cur) {
        if(res != "") {
            return ;
        }
        if(cur == p.size()) {
            res = s;
            return ;
        }
        for(int i = 1; i < 10; i++) {
            if(set.count(i)) {
                continue;
            }
            if(p[cur] == 'I') {
                if(s[s.size() - 1] - '0' < i) {
                    set.insert(i);
                    dfs(s + to_string(i), cur + 1);
                    set.erase(i);
                }
            }
            else {
                if(s[s.size() - 1] - '0' > i) {
                    set.insert(i);
                    dfs(s + to_string(i), cur + 1);
                    set.erase(i);
                }
            }
        }
    }
    string smallestNumber(string pattern) {
        p = pattern;
        for(int i = 1; i < 10; i++) {
            set.insert(i);
            dfs(to_string(i), 0);
            set.erase(i);
        }
        return res;
    }
};