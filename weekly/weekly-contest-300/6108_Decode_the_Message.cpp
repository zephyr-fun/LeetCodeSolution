// 2022.07.03
class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> map;
        int idx = 0;
        for(auto c : key) {
            if(c == ' ') {
                continue;
            }
            if(!map.count(c)) {
                map[c] = 'a' + idx;
                idx++;
            }
        }
        string res = "";
        for(auto c : message) {
            if(c == ' ') {
                res += c;
            }
            else {
                res += map[c];
            }
        }
        return res;
    }
};