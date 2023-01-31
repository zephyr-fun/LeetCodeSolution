// 2023.01.30
typedef long long LL;
class Solution {
public:
    int qmi(int a, int k, int p) {
        int res = 1;
        while(k) {
            if(k & 1) {
                res = (LL)res * a % p;
            }
            k >>= 1;
            a = (LL)a * a % p;
        }
        return res;
    }
    int monkeyMove(int n) {
        const int mod = 1e9 + 7;
        auto power = [&](long long a, long long b) {
            long long y = 1;
            for(; b; b >>= 1) {
                if(b & 1) {
                   y = y * a % mod;
                }
                a = a * a % mod;
            }
            return y;
        };
        long long res = qmi(2, n, mod);
        res = (res - 2 + mod) % mod;
        return res;
    }
};