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