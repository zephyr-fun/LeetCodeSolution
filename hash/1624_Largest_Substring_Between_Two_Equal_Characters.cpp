// 2022.09.17
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int res = -1;
        unordered_map<char, int> map;
        for(int i = 0; i < s.size(); i++) {
            if(!map.count(s[i])) {
                map[s[i]] = i;
            }
            else {
                res = max(res, i - map[s[i]] - 1);
            }
        }
        return res;
    }
};