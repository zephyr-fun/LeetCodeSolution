// 2022.09.26
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n % 2) {
            return false;
        }
        int x = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(' || locked[i] == '0') {
                x++;
            }
            else if(x > 0) {
                x--;
            }
            else {
                return false;
            }
        }
        // 两次判断的原因是正向遍历无法区分左括号多的情况，比如
        // "(((((("
        // "110110"
        x = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == ')' || locked[i] == '0') {
                x++;
            }
            else if(x > 0) {
                x--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};