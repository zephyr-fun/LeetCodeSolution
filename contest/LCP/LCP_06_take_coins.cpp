// 2023.09.20
class Solution {
public:
    int minCount(vector<int>& coins) {
        int res = 0;
        for (auto& coin: coins) {
            res += coin % 2 ? coin / 2 + 1 : coin / 2;
        }
        return res;
    }
};