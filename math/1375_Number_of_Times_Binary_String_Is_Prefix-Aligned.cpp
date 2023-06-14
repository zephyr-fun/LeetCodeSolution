// 2023.06.14
class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int n = flips.size();
        int curmax = 0;
        int res = 0;
        for(int i = 0; i < n; i++) {
            curmax = max(curmax, flips[i]);
            res += curmax == i + 1;
        }
        return res;
    }
};