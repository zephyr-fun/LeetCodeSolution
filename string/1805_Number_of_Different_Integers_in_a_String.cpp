// 2022.12.06
// double pointer
class Solution {
public:
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
    int numDifferentIntegers(string word) {
        int n = word.size();
        int l = 0;
        int r = 0;
        unordered_set<string> set;
        while(r < n) {
            while(l < n && r < n && !isDigit(word[l])) {
                l++;
                r++;
            }
            while(r < n && isDigit(word[r])) {
                r++;
            }
            if(l < r) {
                string temp = word.substr(l, r - l);
                int idx = 0;
                while(temp[idx] == '0') {
                    idx++;
                }
                temp = temp.substr(idx);
                set.insert(temp);
            }
            l = r;
        }
        return set.size();
    }
};