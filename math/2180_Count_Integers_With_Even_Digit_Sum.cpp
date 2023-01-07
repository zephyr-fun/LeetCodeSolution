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