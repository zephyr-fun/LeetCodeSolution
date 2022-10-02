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