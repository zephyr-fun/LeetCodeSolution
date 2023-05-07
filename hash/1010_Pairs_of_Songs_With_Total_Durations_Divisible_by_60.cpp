// 2023.05.07
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt[60];
        memset(cnt, 0, sizeof(cnt));
        int res = 0;
        for(auto& t : time) {
            res += cnt[(60 - t % 60) % 60];
            cnt[t % 60]++;
        }
        return res;
    }
};