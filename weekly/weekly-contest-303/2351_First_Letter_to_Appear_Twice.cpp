// 2022.07.24
class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> set;
        for(auto c : s) {
            if(set.count(c)) {
                return c;
            }
            set.insert(c);
        }
        return '0';
    }
};

// 2023.01.01
class Solution {
public:
    char repeatedCharacter(string s) {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for(auto& c : s) {
            cnt[c - 'a']++;
            if(cnt[c - 'a'] == 2) {
                return c;
            }
        }
        return ' ';
    }
};