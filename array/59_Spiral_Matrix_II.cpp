// 2022.03.26
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startX = 0, startY = 0;
        int loop = n / 2;
        int mid = n / 2;
        int count = 1;
        int offset = 1;
        int i, j;
        while(loop--){
            i = startX;
            j = startY;

            for(; j < startY + n - offset; j++){
                res[i][j] = count;
                count++;
            }
            for(; i < startX + n - offset; i++){
                res[i][j] = count;
                count++;
            }
            for(; j > startY; j--){
                res[i][j] = count;
                count++;
            }
            for(; i > startX; i--){
                res[i][j] = count;
                count++;
            }
            startX++;
            startY++;
            offset += 2; // left and right both reduce 1
        }
        if(n % 2 != 0){
            res[mid][mid] = count;
        }
        return res;
    }
};