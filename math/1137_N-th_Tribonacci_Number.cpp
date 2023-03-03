// 2023.03.03
class Solution {
public:
    int tribonacci(int n) {
        int tribo[3];
        tribo[0] = 0;
        tribo[1] = 1;
        tribo[2] = 1;
        int tot = n - 2;
        if(n <= 2) {
            return tribo[n];
        }
        for(int i = 0; i < tot; i++) {
            tribo[i % 3] = tribo[0] + tribo[1] + tribo[2];
        }
        return tribo[(tot - 1) % 3];
    }
};