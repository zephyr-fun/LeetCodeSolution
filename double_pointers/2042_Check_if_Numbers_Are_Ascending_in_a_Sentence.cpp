// 2023.01.03
class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = -1;
        int cur = -1;
        int n = s.size();
        int left = 0;
        int right = 0;
        while(right < n) {
            while(right < n && (s[right] < '0' || s[right] > '9')) {
                right++;
            }
            left = right;
            while(right < n && s[right] >= '0' && s[right] <= '9') {
                right++;
            }
            prev = cur;
            if(right > left) {
                cur = stoi(s.substr(left, right - left));
                if(cur <= prev) {
                    return false;
                }
            }
            
        }
        return true;
    }
};