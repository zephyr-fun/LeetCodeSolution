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

// 2022.05.21
// dp
class Solution {
public:
    int countNumbersWithUniqueDigits(int _n) {
        // f[i][j] = i * (i + 1) * ...... * (j - 1) * j
        int f[10][10];
        for(int i = 1; i < 10; i++) {
            for(int j = 1; j < 10; j++) {
                int cur = 1;
                for(int k = i; k <= j; k++) {
                    cur *= k;
                }
                f[i][j] = cur;
            }
        }
        int x = int(pow(10, _n) - 1);
        int t = x;
        vector<int> nums;
        while(x != 0) {
            nums.push_back(x % 10);
            x /= 10;
        }
        int n = nums.size();
        if(n <= 1) {
            return t + 1;
        }
        // same len
        int res = 0;
        for(int i = n - 1, p = 1, s = 0; i >= 0; i--, p++) {
            int cur = nums[i];
            int cnt = 0;
            // calc valid num
            for(int j = cur - 1; j >= 0; j--) {
                if(i == n - 1 && j == 0) {
                    continue;
                }
                if(((s >> j) & 1) == 0) {
                    cnt++;
                }
            }
            int a = 10 - p;
            int b = a - (n - p) + 1;
            res += b <= a ? cnt * f[b][a] : cnt;
            if(((s >> cur) & 1) == 1) {
                break;
            }
            s |= (1 << cur);
            if(i == 0) {
                res++;
            }
        }
        // less len
        res += 10;
        for(int i = 2, last = 9; i < n; i++) {
            int cur = last * (10 - i + 1);
            res += cur;
            last = cur;
        }
        return res;
    }
};