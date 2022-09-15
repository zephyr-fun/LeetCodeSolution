// 2022.09.15
// 1->n Square number
// sqrt(n) * sqrt(n) <= n
// given a <= sqrt(n), a * a can be a Square number, which <= n
class Solution {
public:
    int bulbSwitch(int n) {
    //     if(n == 0) {
    //         return 0;
    //     }
    //     if(n == 1) {
    //         return 1;
    //     }
    //     cout << n << endl;
    //     return bulbSwitch(n - 1) + (n - (int)sqrt(n) * (int)sqrt(n) == 0 ? 1 : 0);
    return (int)sqrt(n);
    }
};