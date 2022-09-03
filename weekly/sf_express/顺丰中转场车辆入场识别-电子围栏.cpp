// 2022.06.19
class Solution {
public:
    bool isPointInPolygon(double x, double y, vector<double>& coords) {
        int edgeCnt = coords.size() / 2;
        int cross = 0;
        for(int i = 0; i < coords.size() - 2; i += 2) {
            double x1 = coords[i];
            double y1 = coords[i + 1];
            double x2 = coords[i + 2];
            double y2 = coords[i + 3];
            // cout << x1 << y1 << x2 << y2 << endl;
            if(y1 == y2) {
                continue;
            }
            if(y < min(y1, y2)) {
                continue;
            }
            if(y > max(y1, y2)) {
                continue;
            }
            
            double tar = (double)(y - y1) * (double)(x2 - x1) / (double)(y2 - y1) + x1;
            if(tar >= x) {
                cross++;
            }
        }
        if((cross % 2) == 1) {
            return true;
        }
        return false;
    }
};