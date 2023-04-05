// 2022.10.02
class Solution {
public:
    int commonFactors(int a, int b) {
        int maxVal = min(a, b);
        int res = 0;
        for(int i = 1; i <= maxVal; i++) {
            if(!(a % i) && !(b % i)) {
                res++;
            }
        }
        return res;
    }
};

// 2023.04.05
class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    int commonFactors(int a, int b) {
        int g = gcd(a, b);
        int res = 0;
        for(int i = 1; i * i <= g; i++) {
            if(g % i == 0) {
                res++;
                res += i * i < g;
            }
        }
        return res;
    }
};