// 2022.03.24
// Brute-force search
class Solution {
public:
    int mySqrt(int x) {
        int i = 1;
        while((long long)i*i <= x){
            i++;
        }
        return i-1;
    }
};
// binary search
class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if((long long)mid * mid > x){
                r = mid - 1;
            }
            else if((long long)mid * mid < x){
                l = mid + 1;
            }
            else{
                // mid * mid == x
                return mid;
            }
        }
        return (long long) l * l <= x ? l : l - 1;
    }
};
// newton, hard
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        double C = x, x0 = x;
        while (true) {
            double xi = 0.5 * (x0 + C / x0);
            if (fabs(x0 - xi) < 1e-7) {
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }
};

// 2022.04.16
class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if((long long)mid * mid < x) { // notice longlong
                left = mid + 1;
            }
            else if((long long)mid * mid > x) {
                right = mid - 1;
            }
            else {
                return mid;
            }
        }
        return (long long)left * left <= x ? left : left - 1;
    }
};

// 2022.05.18
class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;
        int res = 0;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if((long long) mid * mid <= x) {
                left = mid + 1;
                res = mid;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};