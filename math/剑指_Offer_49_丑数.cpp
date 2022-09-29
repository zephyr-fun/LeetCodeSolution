// 2022.09.29
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ug(n + 1, 0);
        ug[1] = 1;
        int p2 = 1;
        int p3 = 1;
        int p5 = 1;
        for(int i = 2; i <= n; i++) {
            int num2 = ug[p2] * 2;
            int num3 = ug[p3] * 3;
            int num5 = ug[p5] * 5;
            ug[i] = min(num2, min(num3, num5));
            if(ug[i] == num2) {
                p2++;
            }
            if(ug[i] == num3) {
                p3++;
            }
            if(ug[i] == num5) {
                p5++;
            }
        }
        return ug[n];
    }
};