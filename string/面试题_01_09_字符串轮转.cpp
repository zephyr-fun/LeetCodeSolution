// 2022.09.29
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size() != s2.size()) {
            return false;
        }
        s2 += s2;
        if(s2.find(s1) != string::npos) {
            return true;
        }
        return false;
    }
};