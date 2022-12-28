// 2022.12.28
class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right) {
            if(s[left] == s[right]) {
                while(left < right && s[left] == s[left + 1]) {
                    left++;
                }
                while(left < right && s[right] == s[right - 1]) {
                    right--;
                }
                left++;
                right--;
            }
            else {
                break;
            }
        }
        return right - left >= 0 ? right - left + 1 : 0;
    }
};

// optim
class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right && s[left] == s[right]) {
            char cur = s[left];
            while(left <= right && s[left] == cur) {
                left++;
            }
            while(left <= right && s[right] == cur) {
                right--;
            }
        }
        return right - left + 1;
    }
};