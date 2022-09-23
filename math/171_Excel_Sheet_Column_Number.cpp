// 2022.09.23
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for(auto& c : columnTitle) {
            int temp = c - 'A' + 1;
            res = res * 26 + temp;
        }
        return res;
    }
};