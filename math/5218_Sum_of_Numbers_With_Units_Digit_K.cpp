// 2022.06.19
class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num == 0) {
            return 0;
        }
        for(int i = 1; i <= 10; i++) {
            if(num % 10 == i * k % 10) {
                if(i * k <= num) {
                    return i;
                }
            }
        }
        return -1;
    }
};