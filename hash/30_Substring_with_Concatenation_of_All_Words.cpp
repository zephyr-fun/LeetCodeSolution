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


// 2022.12.05
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        unordered_map<string, int> mapw;
        int n = s.size();
        int m = words.size();
        int w = words[0].size();
        for(auto& word : words) {
            mapw[word]++;
        }
        for(int i = 0; i <= n - m * w; i++) {
            unordered_map<string, int> maps;
            string cur = s.substr(i, m * w);
            for(int j = 0; j < m * w; j += w) {
                if(!mapw.count(cur.substr(j, w))) {
                    break;
                }
                maps[cur.substr(j, w)]++;
            }
            if(mapw == maps) {
                res.emplace_back(i);
            }
        }
        return res;
    }
};

// sliding window && hash by mod
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int m = words.size();
        int w = words[0].size();
        vector<int> res;
        unordered_map<string, int> mapw;
        for(auto& word : words) {
            mapw[word]++;
        }
        for(int i = 0; i < w; i++) {
            unordered_map<string, int> maps;
            for(int j = i; j <= n - w; j += w) {
                string cur = s.substr(j, w);
                maps[cur]++;
                if(j >= i + (m * w)) {
                    int idx = j - m * w;
                    string prev = s.substr(idx, w);
                    if(maps[prev] == 1) {
                        maps.erase(prev);
                    }
                    else {
                        maps[prev]--;
                    }
                    // mapw.count(prev) is needed, otherwise mapw[prev] will be written as 0
                    if(mapw.count(prev) && maps[prev] != mapw[prev]) {
                        continue;
                    }
                }
                // mapw.count(cur) is needed
                if(mapw.count(cur) && maps[cur] != mapw[cur]) {
                    continue;
                }
                if(maps == mapw) {
                    res.emplace_back(j - (m - 1) * w);
                }
            }
        }
        return res;
    }
};