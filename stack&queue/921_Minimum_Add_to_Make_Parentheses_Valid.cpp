// 2022.10.04
class Solution {
public:
    int minAddToMakeValid(string s) {
        int left = 0;
        int right = 0;
        for(auto& c : s) {
            if(c == '(') {
                left++;
            }
            else {
                if(left > 0) {
                    left--;
                }
                else {
                    right++;
                }
            }
        }
        return left + right;
    }
};