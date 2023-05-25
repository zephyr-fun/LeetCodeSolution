// 2023.05.25
// 构造键的唯一性
class Solution {
public:
    string oddString(vector<string>& words) {
        unordered_map<string, vector<string>> map;
        int n = words[0].size();
        for(auto& word : words) {
            string temp = "";
            for(int i = 1; i < n; i++) {
                temp += to_string(word[i] - word[i - 1]);
                temp += '-';
            }
            map[temp].emplace_back(word);
        }
        for(auto& [key, val] : map) {
            if(val.size() == 1) {
                return val[0];
            }
        }
        return "";
    }
};