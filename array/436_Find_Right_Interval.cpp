// 2022.05.20
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<vector<int>, int> map;
        for(int i = 0; i < intervals.size(); i++) {
            map[intervals[i]] = i;
        }
        sort(intervals.begin(), intervals.end());
        vector<int> res(intervals.size(), -1);
        for(int i = 0; i < intervals.size(); i++) {
            int endI = intervals[i][1];
            int left = 0;
            int right = intervals.size() - 1;
            int pos = -1;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(intervals[mid][0] >= endI) {
                    pos = mid;
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            if(pos != -1) {
                res[map[intervals[i]]] = map[intervals[pos]];
            }
            else {
                res[map[intervals[i]]] = -1;
            }
        }
        return res;
    }
};