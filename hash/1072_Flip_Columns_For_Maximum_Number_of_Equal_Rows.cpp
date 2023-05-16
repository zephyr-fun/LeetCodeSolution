// 2023.05.15
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<vector<bool>, int> map;
        int res = 0;
        for(auto& e : matrix) {
            vector<bool> row(e.begin(), e.end());
            if(e[0]) {
                row.flip();
            }
            res = max(res, ++map[row]); // ++map[move(row)] ?
        }
        return res;
    }
};