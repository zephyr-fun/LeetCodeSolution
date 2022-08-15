// 2022.08.14 contest 2022.08.15 update
class Solution {
public:
    int countSpecialNumbers(int n) {
        int f[11][11];
        for(int i = 1; i < 11; i++) {
            for(int j = 1; j < 11; j++) {
                int cur = 1;
                for(int k = i; k <= j; k++) {
                    cur *= k;
                }
                f[i][j] = cur;
            }
        }
        int t = n;
        vector<int> nums;
        while(t != 0) {
            nums.emplace_back(t % 10);
            t /= 10;
        }
        int len = nums.size();
        if(len <= 1) {
            return n;
        }
        int res = 0;
        for(int i = len - 1, p = 1, s = 0; i >= 0; i--, p++) {
            int cur = nums[i];
            int cnt = 0;
            for(int j = cur - 1; j >= 0; j--) {
                if(i == len - 1 && j == 0) {
                    continue;
                }
                if(((s >> j) & 1) == 0) {
                    cnt++;
                }
            }
            int a = 10 - p;
            int b = a - (len - p) + 1;
            res += b <= a ? cnt * f[b][a] : cnt;
            if(((s >> cur) & 1) == 1) {
                break;
            }
            s |= (1 << cur);
            if(i == 0) {
                res++;
            }
        }
        res += 9;
        for(int i = 2,last = 9; i < len; i++) {
            int cur = last * (10 - i + 1);
            res += cur;
            last = cur;
        }
        return res;
    }
};