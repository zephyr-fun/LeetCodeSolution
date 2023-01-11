// 2023.01.11
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(coordinates[0][0] != coordinates[1][0]) {
            double k = (((double)coordinates[0][1] - (double)coordinates[1][1])) / ((double)coordinates[0][0] - (double)coordinates[1][0]);
            for(int i = 1; i < n; i++) {
                double temp = (((double)coordinates[i - 1][1] - (double)coordinates[i][1])) / ((double)coordinates[i - 1][0] - (double)coordinates[i][0]);
                if(temp != k) {
                    return false;
                }
            }
        }
        else {
            for(int i = 1; i < n; i++) {
                if(coordinates[i][0] != coordinates[i - 1][0]) {
                    return false;
                }
            }
        }
        return true;
    }
};

// optim
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        int x0 = coordinates[0][0];
        int y0 = coordinates[0][1];
        for(auto& coor : coordinates) {
            coor[0] -= x0;
            coor[1] -= y0;
        }
        // Ax + By = 0, with (x1, y1)
        // Ax1 + By1 = 0
        // A = y1, B = -x1
        int A = coordinates[1][1];
        int B = -coordinates[1][0];
        for(int i = 2; i < n; i++) {
            if(coordinates[i][0] * A + coordinates[i][1] * B != 0) {
                return false;
            }
        }
        return true;
    }
};