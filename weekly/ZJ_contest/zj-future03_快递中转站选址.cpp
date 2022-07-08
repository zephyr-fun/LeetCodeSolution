// 2022.07.08
class Solution {
public:
    int buildTransferStation(vector<vector<int>>& area) {
        int n = area.size();
        int m = area[0].size();
        vector<int> row;
        vector<int> col;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(area[i][j] == 1) {
                    row.emplace_back(i);
                    col.emplace_back(j);
                }
            }
        }
        return minDis(row) + minDis(col);
    }
    int minDis(vector<int> v) {
        int res = 0;
        sort(v.begin(), v.end());
        int i = 0;
        int j = v.size() - 1;
        while(i < j) {
            res += v[j] - v[i];
            j--;
            i++;
        }
        return res;
    }
};