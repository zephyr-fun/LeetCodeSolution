// 2023.01.30
class Solution {
public:
    int distinctIntegers(int n) {
        return n == 1 ? 1 : n - 1;
    }
};

// n % (n - 1) = 1, n -> n - 1, n - 1 -> n - 2 ......