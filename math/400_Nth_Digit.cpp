// 2022.08.24
typedef long long int64;
class Solution {
public:
    int findNthDigit(int n) {
        int64 end = 9;
        int64 len = 1;
        int64 start = 1;
        while(n - len * end > 0) {
            n -= len * end;
            len++;
            start *= 10;
            end *= 10;
        }
        start += (n + len - 1) / len - 1;
        n = n % len ? n % len : len;
        return to_string(start)[n - 1] - '0';
    }
};