// 2022.12.13
class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for(int i = 0; i < n; i++) {
            for(int c = 0; c < 3 && s[i] == '?'; c++) {
                bool flag = true;
                if(i - 1 >= 0 && s[i - 1] == c + 'a') {
                    flag = false;
                }
                if(i + 1 < n && s[i + 1] == c + 'a') {
                    flag = false;
                }
                if(flag) {
                    s[i] = c + 'a';
                    break;
                }
            }
        }
        return s;
    }
};