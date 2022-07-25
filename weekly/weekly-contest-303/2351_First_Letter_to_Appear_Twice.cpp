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