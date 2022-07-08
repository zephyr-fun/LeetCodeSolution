// 2022.07.08
class Solution {
public:
    bool canReceiveAllSignals(vector<vector<int>>& intervals) {
        map<int, int> map;
        int n = intervals.size();
        for(auto iter : intervals) {
            map[iter[0]]++;
            map[iter[1]]--;
        }
        int cur = 0;
        for(auto [k, v] : map) {
            cur += v;
            if(cur > 1) {
                return false;
            }
        }
        return true;
    }
};