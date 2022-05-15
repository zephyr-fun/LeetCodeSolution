// 2022.05.15
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int res = 0;
        sort(special.begin(), special.end());
        res = max(res, special[0] - bottom);
        for(int i = 0; i < special.size() - 1; i++) {
            res = max(res, special[i + 1] - special[i] - 1);
        }
        res = max(res, top - special[special.size() - 1]);
        return res;
    }
};