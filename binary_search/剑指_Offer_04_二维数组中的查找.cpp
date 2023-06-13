// 2022.08.13
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) {
            return false;
        }
        int m = matrix[0].size();
        int i = 0;
        int j = m - 1;
        while(i < n && j >= 0) {
            if(matrix[i][j] > target) {
                j--;
            }
            else if(matrix[i][j] < target) {
                i++;
            }
            else {
                return true;
            }
        }
        return false;
    }
};

// 2022.08.27
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) {
            return false;
        }
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        int col = m - 1;
        while(row < n && col >= 0) {
            if(matrix[row][col] > target) {
                col--;
            }
            else if(matrix[row][col] < target) {
                row++;
            }
            else {
                return true;
            }
        }
        return false;
    }
};

// 2023.06.13
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) {
            return false;
        }
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        int col = m - 1;
        while(row < n && col >= 0) {
            if(matrix[row][col] > target) {
                col--;
            }
            else if(matrix[row][col] < target) {
                row++;
            }
            else {
                return true;
            }
        }
        return false;
    }
};