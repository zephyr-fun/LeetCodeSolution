// 2023.01.12
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> map;
        for(auto& k : knowledge) {
            map[k[0]] = k[1];
        }
        int left = 0;
        int right = 0;
        int n = s.size();
        string res = "";
        string key = ""; // nice
        bool is_re = false;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                is_re = true;
            }
            else if(s[i] == ')') {
                res += map.count(key) ? map[key] : "?";
                key = "";
                is_re = false;
            }
            else {
                if(is_re) {
                    key += s[i];
                }
                else {
                    res += s[i];
                }
            }
        }
        return res;
    }
};