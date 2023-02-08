// 2023.02.08
// greedy
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> res;
        sort(folder.begin(), folder.end());
        int n = folder.size();
        res.emplace_back(folder[0]);
        int size;
        for(int i = 1; i < n; i++) {
            size = res.back().size();
            if(folder[i].size() > size && folder[i].substr(0, size + 1) == res.back() + '/') {
                continue;
            }
            res.emplace_back(folder[i]);
        }
        return res;
    }
};

// trie