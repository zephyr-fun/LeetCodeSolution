// 2022.08.01
class Solution {
public:
    string generateTheString(int n) {
        string res = "";
        if(n & 1) {
            for(int i = 0; i < n; i++) {
                res += 'a';
            }
        }
        else {
            for(int i = 1; i < n; i++) {
                res += 'a';
            }
            res += 'b';
        }
        return res;
    }
};