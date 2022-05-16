// 2022.05.16
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int count[32];
        int res = 0;
        memset(count, 0, sizeof(count));
        for(int i = 0; i < candidates.size(); i++) {
            int candidate = candidates[i];
            for(int j = 0; j < 32; j++) {
                if((candidate & (1 << j)) != 0) {
                    count[j]++;
                    res = max(res, count[j]);
                }
            }
        }
        return res;
    }
};