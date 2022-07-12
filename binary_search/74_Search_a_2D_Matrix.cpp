// 2022.07.12
// convert to 1 dim
class Solution {
public:
    int getIdx(int x, int y, int m) {
        return x * m + y;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0;
        int right = getIdx(n - 1, m - 1, m);
        while(left <= right) {
            int mid = (left + right) >> 1;
            int midx = mid / m;
            int midy = mid % m;
            if(matrix[midx][midy] < target) {
                left = mid + 1;
            }
            else if(matrix[midx][midy] > target) {
                right = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};