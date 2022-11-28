// 2022.09.09
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n) {
            n = n & (n - 1);
            res++;
        }
        return res;
    }
};

// 2022.11.28
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for(int i = 0; i < 32; i++) {
            res += (n >> i) & 1;
        }
        return res;
    }
};

// 2022.11.28
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n) {
            res++;
            n -= lowbit(n);
        }
        return res;
    }

private:
    static inline uint32_t lowbit(uint32_t x) {
        return x & (-x);
    }
};