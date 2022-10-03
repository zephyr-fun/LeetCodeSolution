// 2022.10.03
// pattern recognition
class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 1;
        int n = s.size();
        for(int i = 1; i < n; i++) {
            if(s[i - 1] == '0' && s[i] == '1') {
                cnt++;
            }
        }
        return cnt <= 1;
    }
};

// way 2
class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos;
    }
};