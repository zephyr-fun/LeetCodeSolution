// 2023.01.10
class Solution {
public:
    int divide(int dividend, int divisor) {
        vector<long long> exp;
        bool is_minus = false;
        if(dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0) {
            is_minus = true;
        }
        long long a = abs((long long) dividend);
        long long b = abs((long long) divisor);
        for(long long i = b; i <= a; i = i + i) {
            exp.emplace_back(i);
        }
        long long res = 0;
        for(int i = exp.size() - 1; i >= 0; i--) {
            if(a >= exp[i]) {
                a -= exp[i];
                res += 1ll << i;
            }
        }
        if(is_minus) {
            res = -res;
        }
        if(res > INT_MAX || res < INT_MIN) {
            res = INT_MAX;
        }
        return res;
    }
};