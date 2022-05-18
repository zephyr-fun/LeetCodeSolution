// 2022.05.18
class Solution {
public:
    int row;
    int col;
    vector<vector<int>> matrix_;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        row = matrix.size();
        col = matrix[0].size();
        matrix_ = matrix;
        int left = matrix[0][0];
        int right = matrix[row - 1][col - 1];
        int pos = 0; // pos good
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int val = getVal(mid);
            cout << "left:" << left << "right:" << right << "mid:" << mid << "val:" << val << endl;
            if(val >= k) {
                right = mid - 1;
                pos = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return pos;
    }
    int getVal(int mid) {
        int i = row - 1;
        int j = 0;
        int res = 0;
        while(i >= 0 && j < col) { // note i >= 0
            if(matrix_[i][j] > mid) {
                i--;
            }
            else {
                res += i + 1;
                j++;
            }
        }
        return res;
    }
};