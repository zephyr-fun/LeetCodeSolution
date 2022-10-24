// 2022.10.24
class Solution {
public:
    string count(string s) {
        int n = s.size();
        string res = "";
        int left = 0;
        int right = 0;
        while(right < n) {
            while(right < n && s[right] == s[right + 1]) {
                right++;
            }
            res += to_string(right - left + 1);
            res += s[left];
            right++;
            left = right;
        }
        return res;
    }
    string countAndSay(int n) {
        if(n == 1) {
            return "1";
        }
        return count(countAndSay(n - 1));
    }
};