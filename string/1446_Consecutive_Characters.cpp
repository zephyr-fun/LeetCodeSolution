// 2022.05.22
class Solution {
public:
    int maxPower(string s) {
        int len = 1;
        int res = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i - 1]) {
                len++;
                res = max(res, len);
            }
            else {
                len = 1;
            }
        }
        return res;
    }
};