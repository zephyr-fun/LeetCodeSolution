// 2023.01.13
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int maps[26];
        int mapt[26];
        memset(maps, 0, sizeof(maps));
        memset(mapt, 0, sizeof(mapt));
        for(auto& c : s) {
            maps[c - 'a']++;
        }
        for(auto& c : target) {
            mapt[c - 'a']++;
        }
        int res = 0x3f3f3f3f;
        for(auto& c : target) {
            res = min(res, maps[c - 'a'] / mapt[c - 'a']);
        }
        return res;
    }
};