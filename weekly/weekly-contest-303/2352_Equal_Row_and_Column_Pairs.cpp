// 2022.07.24
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                bool ok = true;
                for(int k = 0; k < n; k++) {
                    if(grid[i][k] != grid[k][j]) {
                        ok = false;
                        break;
                    }
                }
                if(ok) {
                    res++;
                }
            }
        }
        return res;
    }
};

// 2023.06.06
// O(n^2)
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<string, int> map;
        int n = grid.size();
        int m = grid[0].size();
        string temp;
        for(int i = 0; i < n; i++) {
            temp = "";
            for(int j = 0; j < m; j++) {
                temp += to_string(grid[i][j]);
                temp += ',';
            }
            temp.pop_back();
            map[temp]++;
        }
        int res = 0;
        for(int i = 0; i < m; i++) {
            temp = "";
            for(int j = 0; j < n; j++) {
                temp += to_string(grid[j][i]);
                temp += ',';
            }
            temp.pop_back();
            res += map[temp];
        }
        return res;
    }
};