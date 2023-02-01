// 2023.01.06
class Solution {
public:
    int cnt(int n) {
        int res = 0;
        while(n) {
            res += n % 10;
            n /= 10;
        }
        // cout << res << " " << !(res & 1) << endl;
        return !(res & 1);
    }
    int countEven(int num) {
        int res = 0;
        for(int i = 1; i <= num; i++) {
            if(cnt(i)) {
                res++;
            }
        }
        return res;
    }
};

// 2023.02.01
// math
// xyz0 -> xyzd
// 0 -> xyz0 [a, a + 10]
class Solution {
public:
    int countEven(int num) {
        int t = 0;
        int d = num % 10;
        int a = num - d;
        num = a;
        while(num) {
            t += num % 10;
            num /= 10;
        }
        return a / 2 - 1 + (t % 2 == 0 ? d / 2 + 1 : ++d / 2); 
    }
};

// optim
class Solution {
public:
    int countEven(int num) {
        int t = 0;
        int cur = num;
        while(cur) {
            t += cur % 10;
            cur /= 10;
        }
        return t % 2 == 1 ? --num / 2 : num / 2;
    }
};