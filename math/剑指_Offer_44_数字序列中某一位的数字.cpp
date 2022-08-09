// 2022.08.09
class Solution {
public:
    int findNthDigit(int n) {
        long long k = 1;
        long long t = 9;
        long long s = 1;
        while(n > k * t) {
            n -= k * t;
            k++;
            t *= 10;
            s *= 10;
        }
        s += (n + k - 1) / k - 1;
        n = n % k ? n % k : k;
        return to_string(s)[n - 1] - '0';
    }
};