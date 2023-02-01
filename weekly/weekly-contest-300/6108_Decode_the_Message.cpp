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

// 2023.02.01
class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> map;
        char cur = 'a';
        for(auto& c : key) {
            if(!map.count(c) && c >= 'a' && c <= 'z') {
                map[c] = cur;
                cur++;
            }
        }
        string res = "";
        for(auto& c : message) {
            if(c >= 'a' && c <= 'z') {
                res += map[c];
            }
            else {
                res += c;
            }
        }
        return res;
    }
};