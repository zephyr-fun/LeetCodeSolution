// 2023.03.30
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int res = 0;
        sort(points.begin(), points.end(), [&] (vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        int n = points.size();
        for(int i = 1; i < n; i++) {
            res = max(res, points[i][0] - points[i - 1][0]);
        }
        return res;
    }   
};