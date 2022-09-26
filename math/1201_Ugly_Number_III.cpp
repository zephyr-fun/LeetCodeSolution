// 2022.09.26
// 容斥原理
typedef long long LL;
class Solution {
public:
    LL gcd(LL a, LL b) {
        return b ? gcd(b, a % b) : a;
    }

    LL lcm(LL a, LL b) {
        return a * b / gcd(a, b);
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        LL ab = lcm(a, b);
        LL ac = lcm(a, c);
        LL bc = lcm(b, c);
        LL abc = lcm(ab, c);
        LL left = 0;
        LL right = 2e9;
        int res = 0;
        while(left <= right) {
            LL mid = left + (right - left) / 2;
            LL cnt = mid / a + mid / b + mid / c - mid / ab - mid / ac - mid / bc + mid / abc;
            if(cnt >= n) {
                res = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
};