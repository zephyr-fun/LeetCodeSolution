// 2022.05.12
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row = strs.size();
        if(row <= 1) {
            return 0;
        }
        int column = strs[0].size();
        int res = 0;
        for(int j = 0; j < column; j++) {
            for(int i = 1; i < row; i++) {
                if(strs[i][j] < strs[i - 1][j]) {
                    res += 1;
                    break;
                }
            }
        }
        return res;
    }
};