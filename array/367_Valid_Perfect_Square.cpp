// 2022.03.24
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if((long long)mid * mid > num){
                right = mid - 1;
            }
            else if((long long)mid *mid < num){
                left = mid + 1;
            }
            else{
                // mid*mid == num
                return true;
            }
        }
        return false;
    }
};

// 2022.04.16
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = num;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if((long long)mid *mid < num) {
                left = mid + 1;
            }
            else if((long long)mid * mid > num) {
                right = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};