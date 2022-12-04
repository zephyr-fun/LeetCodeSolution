// 2022.12.04
// polar angle & sliding window
#include<cmath>
class Solution {
public:
    double eps = 1e-9;
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int x = location[0];
        int y = location[1];
        vector<double> plist;
        int cnt = 0;
        double pi = M_PI;
        double t = angle * pi / 180;
        for(auto& p : points) {
            int a = p[0];
            int b = p[1];
            if(a == x && b == y && ++cnt >= 0) {
                continue;
            }
            plist.emplace_back(atan2(b - y, a - x) + pi);
        }
        sort(plist.begin(), plist.end());
        int n = plist.size();
        int maxVal = 0;
        for(int i = 0; i < n; i++) {
            plist.emplace_back(plist[i] + 2 * pi);
        }
        for(int l = 0, r = 0; r < 2 * n; r++) {
            while(l < r && plist[r] - plist[l] > t + eps) {
                l++;
            }
            maxVal = max(maxVal, r - l + 1);
        }
        return maxVal + cnt;
    }
};