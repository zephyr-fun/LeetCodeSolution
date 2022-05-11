// 2022.05.04
// https://mp.weixin.qq.com/s/xP9m1Ci6bMX9LRYe3t1X2w
class Solution {
public:
    int lastRemaining(int n) {
        if(n == 1) {
            return n;
        }
        return 2 * (n / 2 + 1 - lastRemaining(n / 2));
    }
};

// 2022.05.11
// f[i] + f'[i] = i + 1
// f[i] = f'[i / 2] * 2
// f[i] = 2 * (i / 2 + 1 - f[i / 2])
class Solution {
public:
    int lastRemaining(int n) {
        if(n == 1) {
            return 1;
        }
        return 2 * (n / 2 + 1 - lastRemaining(n / 2));
    }
};