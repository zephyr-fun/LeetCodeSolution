// 2022.09.07
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        int n = words.size();
        for(int i = 0; i < n; i++) {
            map[words[i]]++;
        }
        vector<pair<string, int>> temp(map.begin(), map.end());
        sort(temp.begin(), temp.end(), [](pair<string, int>& a, pair<string, int>& b) {
            if(a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });
        vector<string> res;
        for(int i = 0; i < k; i++) {
            res.emplace_back(temp[i].first);
        }
        return res;
    }
};

// 2022.09.23
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        vector<string> res;
        for(auto& word : words) {
            map[word]++;
        }
        vector<pair<string, int>> temp(map.begin(), map.end());
        sort(temp.begin(), temp.end(), [](pair<string, int>& a, pair<string, int>& b) {
            if(a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });
        for(int i = 0; i < k; i++) {
            res.emplace_back(temp[i].first);
        }
        return res;
    }
};