// 2022.05.09
class Solution {
public:
    bool isSelfDividingNumber(int num) {
        int temp = num;
        while(temp > 0) {
            int digit = temp % 10;
            if(digit == 0 || num % digit != 0) {
                return false;
            }
            temp /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left; i <= right; i++) {
            if(isSelfDividingNumber(i)) {
                res.push_back(i);
            }
        }
        return res;
    }
};