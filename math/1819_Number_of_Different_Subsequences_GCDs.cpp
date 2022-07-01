// 2022.07.01
class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int maxVal = -0x3f3f3f3f;
        for(auto num : nums) {
            maxVal = max(maxVal, num);
        }
        vector<int> g(maxVal + 1);
        for(auto num : nums) {
            for(int y = 1; y * y <= num; y++) {
                if(num % y == 0) {
                    if(!g[y]) {
                        g[y] = num;
                    }
                    else {
                        g[y] = gcd(g[y], num);
                    }
                    if(y * y != num) {
                        int z = num / y;
                        if(!g[z]) {
                            g[z] = num;
                        }
                        else {
                            g[z] = gcd(g[z], num);
                        }
                    }
                }
            }
        }
        int res = 0;
        for(int i = 1; i <= maxVal; i++) {
            if(g[i] == i) {
                res++;
            }
        }
        return res;
    }
};