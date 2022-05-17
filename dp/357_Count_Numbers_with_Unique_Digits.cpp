// 2022.05.13
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) {
            return 1;
        }
        int res = 10;
        for(int i = 2, last = 9; i <= n; i++) { // init last can not be 0(high bit), so it equals to 9
            int cur = last * (10 - i + 1); // 9 9 8 7 6 5 4 3 2 1.........
            res += cur;
            last = cur;
        }
        return res;
    }
};

// 2022.05.17
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 10;
        if(n == 0) {
            return 1;
        }
        if(n == 1) {
            return res;
        }
        for(int i = 2, last = 9; i <= n; i++) {
            int cur = last * (10 - i + 1);
            res += cur;
            last = cur;
        }
        return res;
    }
};

// dp
