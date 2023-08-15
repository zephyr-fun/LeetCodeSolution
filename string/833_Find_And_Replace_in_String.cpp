// 2023.08.15
// plain version
class Solution {
public:
    string s;
    bool check(int num, string& target) {
        int n = target.size();
        if(n + num > s.size()) {
            return false;
        }
        for(int i = 0; i < n; i++) {
            if(s[i + num] != target[i]) {
                return false;
            }
        }
        return true;
    }
    string findReplaceString(string s_, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        s = s_;
        string res = "";
        int idx = 0;
        int size = indices.size();
        unordered_map<int, pair<string, string>> map;
        for (int i = 0; i < size; i++) {
            map[indices[i]] = make_pair(sources[i], targets[i]);
        }
        sort(indices.begin(), indices.end());
        for (int i = 0; i < s.size(); i++) {
            if (idx < size && i == indices[idx]) {
                if (check(i, map[indices[idx]].first)) {
                    res += map[indices[idx]].second;
                    i += map[indices[idx]].first.size() - 1;
                }
                else {
                    res += s[i];
                }
                idx++;
            }
            else {
                res += s[i];
            }
        }
        return res;
    }
};

// optim
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.size();
        vector<pair<string, int>> replace(n, {"", 1});
        for (int i = 0; i < indices.size(); i++) {
            if (s.compare(indices[i], sources[i].size(), sources[i]) == 0) {
                replace[indices[i]] = {targets[i], sources[i].size()};
            }
        }
        string res = "";
        for (int i = 0; i < n; i += replace[i].second) {
            if(replace[i].first.empty()) {
                res += s[i];
            }
            else {
                res += replace[i].first;
            }
        }
        return res;
    }
};