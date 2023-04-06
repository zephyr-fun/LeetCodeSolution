// 2023.04.06
// 两边展开做推导
class Solution {
public:
    string baseNeg2(int n) {
        if(!n) {
            return "0";
        }
        string res;
        while(n) {
            int r = n & 1;
            res += to_string(r);
            n = (n - r) / -2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};