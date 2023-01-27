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

// 2023.01.27
class Solution {
public:
    string greatestLetter(string s) {
        bool lo[26];
        bool hi[26];
        memset(lo, false, sizeof(lo));
        memset(hi, false, sizeof(hi));
        for(auto& c : s) {
            if(c >= 'a' && c <= 'z') {
                lo[c - 'a'] = true;
            }
            else if(c >= 'A' && c <= 'Z') {
                hi[c - 'A'] = true;
            }
        }
        string res = "";
        for(int i = 0; i < 26; i++) {
            if(hi[i] && lo[i]) {
                res = 'A' + i;
            }
        }
        return res;
    }
};