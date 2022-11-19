// 2022.11.19
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0;
        int cur = 0;
        for(auto& g : gain) {
            cur += g;
            res = max(res, cur);
        }
        return res;
    }
};