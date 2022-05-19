// 2022.05.19
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<int> nums;
        while(n != 0) {
            nums.push_back(n % 10);
            n /= 10;
        }
        int lenN = nums.size();
        vector<int> digit;
        for(int i = 0; i < digits.size(); i++) {
            digit.push_back(digits[i][0] - '0'); // string
        }
        int lenD = digit.size();

        // diff len 
        int res = 0;
        for(int i = 1; i < lenN; i++) {
            res += pow(lenD, i);
        }

        // same len
        for(int i = lenN - 1; i >= 0; i--) {
            int left = 0;
            int right = lenD - 1;
            int pos = 0;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(digit[mid] <= nums[i]) {
                    pos = mid;
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            if(digit[pos] > nums[i]) {
                break;
            }
            else if(digit[pos] == nums[i]) {
                res += pos * pow(lenD, i);
                if(i == 0) {
                    res++;
                }
            }
            else {
                res += (pos + 1) * pow(lenD, i);
                break;
            }
        }
        return res;
    }
};