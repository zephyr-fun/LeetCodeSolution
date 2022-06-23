// 2022.06.23
// unordered_map == != overload
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int m = words.size();
        int w = words[0].size();
        vector<int> res;
        unordered_map<string, int> mapw;
        for(auto word : words) {
            mapw[word]++;
        }
        for(int i = 0; i <= n - m * w; i++) {
            unordered_map<string, int> maps;
            string temp = s.substr(i, m * w);
            for(int i = 0; i < m * w; i += w) {
                if(!mapw.count(temp.substr(i, w))) {
                    break;
                }
                maps[temp.substr(i, w)]++;
            }
            if(maps == mapw) { // here overload
                res.emplace_back(i);
            }
        }
        return res;
    }
};

// optim enumerate
