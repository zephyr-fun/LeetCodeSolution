// 2023.03.02
class Solution {
public:
    string printBin(double num) {
        string res = "0.";
        while(num > 0 && res.size() < 32) {
            num *= 2;
            int x = (int)num;
            res.push_back('0' + x);
            num -= x;
        }
        return num == 0 ? res : "ERROR";
    }
};