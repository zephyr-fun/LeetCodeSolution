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

// 2023.05.14
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size() != s2.size()) {
            return false;
        }
        else if(s1.size() == 0) {
            return true;
        }
        s1 = s1 + s1;
        return s1.find(s2) != string::npos;
    }
};

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size() != s2.size()) {
            return false;
        }
        s1 += s1;
        return s1.find(s2) != string::npos;
    }
};