// 2022.05.15
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        const int N = points.size();
        double res = 0;
        for (int i = 0; i < N - 2; i++) {
            for (int j = i + 1; j < N - 1; j++) {
                for (int k = j + 1; k < N; k++) {
                    auto& point1 = points[i];
                    auto& point2 = points[j];
                    auto& point3 = points[k];
                    int x1 = point1[0], y1 = point1[1];
                    int x2 = point2[0], y2 = point2[1];
                    int x3 = point3[0], y3 = point3[1];
                    res = max(res, 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
                }
            }
        }
        return res;
    }
};