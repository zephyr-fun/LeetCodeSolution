// 2022.11.13
class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> map;
        for(auto c : s) {
            map[c]++;
        }
        string res = "";
        for(int i = 0; i < order.size(); i++) {
            while(map[order[i]] > 0) {
                res += order[i];
                map[order[i]]--;
            }
        }
        for(auto [k, v] : map) {
            while(v > 0) {
                res += k;
                v--;
            }
        }
        return res;
    }
};

// optim hash
class Solution {
public:
    string customSortString(string order, string s) {
        int map[26];
        memset(map, 0, sizeof(map));
        for(auto c : s) {
            map[c - 'a']++;
        }
        string res = "";
        for(int i = 0; i < order.size(); i++) {
            while(map[order[i] - 'a'] > 0) {
                res += order[i];
                map[order[i] - 'a']--;
            }
        }
        for(int i = 0; i < 26; i++) {
            while(map[i] > 0) {
                res += 'a' + i;
                map[i]--;
            }
        }
        return res;
    }
};