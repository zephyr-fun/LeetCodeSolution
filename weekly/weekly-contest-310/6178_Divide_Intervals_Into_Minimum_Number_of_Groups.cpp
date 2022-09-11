// 2022.09.11
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> map;
        int res = 0;
        int cur = 0;
        for(auto inter : intervals) {
            map[inter[0]]++;
            map[inter[1] + 1]--;
        }
        for(auto [k, v] : map) {
            cur += v;
            res = max(res, cur);
        }
        return res;
    }
};