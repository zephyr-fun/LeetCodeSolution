// 2022.06.08
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        auto point1 = points[0];
        auto point2 = points[1];
        auto point3 = points[2];
        int s = point1[0] * point2[1] + point2[0] * point3[1] + point3[0] * point1[1] - point1[0] * point3[1] - point2[0] * point1[1] - point3[0] * point2[1];
        return s == 0 ? false : true;
    }
};