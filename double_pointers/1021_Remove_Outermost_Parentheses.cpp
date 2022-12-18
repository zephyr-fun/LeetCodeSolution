// 2022.05.28
class Solution {
public:
    string removeOuterParentheses(string s) {
        int left = 0;
        int right = 0;
        int count = 0;
        string res;
        while(right < s.size()) {
            if(s[right] == '(') {
                count++;
            }
            else {
                count--;
            }
            if(count == 0) {
                if(right - left - 1 > 0) {
                    res += s.substr(left + 1, right - left - 1);
                }
                left = right + 1;
            }
            right++;
        }
        return res;
    }
};

// 2022.12.18
class Solution {
public:
    string removeOuterParentheses(string s) {
        int left = 0;
        int right = 1;
        int n = s.size();
        int cur = s[0] == '(' ? 1 : -1;
        string res;
        while(right < n) {
            cur += s[right] == '(' ? 1 : -1;
            if(cur == 0) {
                left++;
                while(left < right) {
                    res += s[left];
                    left++;
                }
                left = right + 1;
            }
            right++;
        }
        return res;
    }
};