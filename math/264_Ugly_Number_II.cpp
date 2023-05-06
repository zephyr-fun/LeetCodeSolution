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

// 2022.12.24
class Solution {
public:
    int nthUglyNumber(int n) {
        int p2 = 1;
        int p3 = 1;
        int p5 = 1;
        vector<int> ug(n + 1, 0);
        ug[1] = 1;
        for(int i = 2; i <= n; i++) {
            int num1 = 2 * ug[p2];
            int num2 = 3 * ug[p3];
            int num3 = 5 * ug[p5];
            ug[i] = min(num1, min(num2, num3));
            if(ug[i] == num1) {
                p2++;
            }
            if(ug[i] == num2) {
                p3++;
            }
            if(ug[i] == num3) {
                p5++;
            }
        }
        return ug[n];
    }
};

// 2022.12.25
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ug(n + 1, 0);
        ug[1] = 1;
        int p2 = 1;
        int p3 = 1;
        int p5 = 1;
        for(int i = 2; i <= n; i++) {
            int num2 = 2 * ug[p2];
            int num3 = 3 * ug[p3];
            int num5 = 5 * ug[p5];
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

// 2023.05.06
class Solution {
public:
    int nthUglyNumber(int n) {
        int res[n + 1];
        memset(res, 0, sizeof(res));
        res[1] = 1;
        for(int i = 2, i2 = 1, i3 = 1, i5 = 1; i <= n; i++) {
            int a = res[i2] * 2;
            int b = res[i3] * 3;
            int c = res[i5] * 5;
            res[i] = min(a, min(b, c));
            // separate statement, 10 = 2 * 5
            if(a == res[i]) {
                i2++;
            }
            if(b == res[i]) {
                i3++;
            }
            if(c == res[i]) {
                i5++;
            }
        }
        return res[n];
    }
};