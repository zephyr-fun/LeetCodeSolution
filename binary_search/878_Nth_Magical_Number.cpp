// 2022.11.22
class Solution {
public:
    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    int nthMagicalNumber(int n, int a, int b) {
        int mod = 1e9 + 7;
        long l = 0;
        long r = min(a, b) * (long)n;
        while(l + 1 < r) {
            long mid = l + (r - l) / 2;
            int cnt = mid / (long)a + mid / (long) b - mid * gcd((long)a, (long)b) / (a * b);
            if(cnt >= n) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return r % mod;
    }
};