// 2022.06.23
// set & map remove repeat
class Solution {
public:
    set<string> temp;
    vector<string> res;
    string path;
    void dfs(string& s, unordered_map<char, int>& map, int num) {
        if(num == s.size()) {
            temp.insert(path);
            return ;
        }
        for(int i = 0; i < s.size(); i++) {
            if(map[s[i]] > 0) {
                map[s[i]]--;
                path += s[i];
                dfs(s, map, num + 1);
                path.pop_back();
                map[s[i]]++;
            }
        }
    }
    vector<string> permutation(string s) {
        int n = s.size();
        unordered_map<char, int> map;
        for(int i = 0; i < n; i++) {
            map[s[i]]++;
        }
        dfs(s, map, 0);
        for(auto tmp : temp) {
            res.emplace_back(tmp);
        }
        return res;
    }
};

// sort and state comprision, much faster
class Solution {
public:
    vector<string> res;
    string path;
    void dfs(string& s, vector<bool>& visit, int num) {
        if(num == s.size()) {
            res.emplace_back(path);
            return ;
        }
        for(int i = 0; i < s.size(); i++) {
            if(!visit[i]) {
                visit[i] = true;
                path += s[i];
                dfs(s, visit, num + 1);
                path.pop_back();
                visit[i] = false;
                // remove repeat
                while(i + 1 < s.size() && s[i] == s[i + 1]) {
                    i++;
                }
            } 
        }
    }
    vector<string> permutation(string s) {
        int n = s.size();
        sort(s.begin(), s.end());
        vector<bool> visit(n, false);
        dfs(s, visit, 0);
        return res;
    }
};