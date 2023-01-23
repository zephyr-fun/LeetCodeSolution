// 2023.01.23
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) {
            return false;
        }
        int res = 0;
        while(n > 0) {
            res += n % 2;
            n /= 2;
            if(res > 1) {
                return false;
            }
        }
        return true;
    }
};

// optim
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};