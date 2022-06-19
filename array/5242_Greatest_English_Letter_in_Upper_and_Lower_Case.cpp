// 2022.06.19
class Solution {
public:
    string greatestLetter(string s) {
        int n = s.size();
        int map[26] = {0};
        for(int i = 0; i < n; i++) {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                map[s[i] - 'A'] |= 1; // 001
            }
            else {
                map[s[i] - 'a'] |= 2; // 010
            }
        }
        for(int i = 25; i >= 0; i--) {
            if(map[i] == 3) { // 011
                return string(1, 'A' + i);
            }
        }
        return "";
    }
};