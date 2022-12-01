// 2022.12.01
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int minVal = 0x3f3f3f3f;
        int res = -1;
        int n = points.size();
        for(int i = 0; i < n; i++) {
            if(points[i][0] != x && points[i][1] != y) {
                continue;
            }
            int cur = abs(points[i][0] - x) + abs(points[i][1] - y);
            if(cur < minVal) {
                minVal = cur;
                res = i;
            }
        }
        return minVal == 0x3f3f3f3f ? -1 : res;
    }
};