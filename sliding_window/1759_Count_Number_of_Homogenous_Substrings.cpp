// 2022.12.26
class Solution {
public:
    int countHomogenous(string s) {
        int mod = 1e9 + 7;
        int left = 0;
        int right = 0;
        int n = s.size();
        int res = 0;
        while(right < n) {
            res = (res + right - left + 1) % mod;
            right++;
            if(s[right] != s[left]) {
                left = right;
            }
        }
        return res;
    }
};